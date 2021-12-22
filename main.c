#include "project.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void win(void);
void fail(void);
char keypad(int row, int col);
int assign(char value);
const char *problem(int choice);
int confirm(int choice, int n, char value);
void mathGame(void);
void mazeGame(void);
void ledWrite(void);
void ledWriteLevel2(void);
void ledWriteLevel3(void);
void servo(void);
void smileyFace(void);


int main(void)
{
	LCD_Start();
	CyGlobalIntEnable;
	LCD_Position(0, 0);
	LCD_PrintString("Defuse the bomb!");
	CyDelay(1000);
	LCD_Position(1, 0);
	LCD_PrintString("Let's begin...");
	CyDelay(2000);
	LCD_ClearDisplay();
	mathGame();
}

void smileyFace(void)
{
    LCD_ClearDisplay();
    LCD_Position(0,0);
    LCD_PrintString("Press red button");
    LCD_Position(1,0);
    LCD_PrintString("to restart...");
    for(;;) 
    {
        
        if(rightButton_Read() == 1) 
        {
            main();
        }
        uint8 Row = 0x01;
        int delay = 1;
        
        
        Row_Write(~Row);
        Red_Write(0xBD);
        Green_Write(0xFF);
        Blue_Write(0x18);
        Row = Row  << 1;
        CyDelay(delay);
      
        
        Row_Write(~Row);
        Red_Write(0xBD);
        Green_Write(0xFF);
        Blue_Write(0x18);
        
        Row = Row  << 1;
        CyDelay(delay);
       
        Row_Write(~Row);
        Red_Write(0xBD);
        Green_Write(0xFF);
        Blue_Write(0x18);
        Row = Row  << 1;
        CyDelay(delay);
   
        Row_Write(~Row);
        Red_Write(0xFF);
        Green_Write(0xFF);
        Blue_Write(0xFF);
        
        Row = Row  << 1;
        CyDelay(delay);
      
        Row_Write(~Row);
        Red_Write(0xFF);
        Green_Write(0xE7);
        Blue_Write(0xFF);
       
        Row = Row  << 1;
        CyDelay(delay);
     
        Row_Write(~Row);
        Red_Write(0x7E);
        Green_Write(0xE7);
        Blue_Write(0xFF);
        
        Row = Row  << 1;
        CyDelay(delay);
     
        Row_Write(~Row);
        Red_Write(0xBD);
        Green_Write(0xFF);
        Blue_Write(0xFF);
        
        Row = Row  << 1;
        CyDelay(delay);
        
        Row_Write(~Row);
        Red_Write(0xC3);
        Green_Write(0xFF);
        Blue_Write(0xFF);
        
        CyDelay(delay);
    }
}


void win(void)
{
	CyGlobalIntEnable;
    LCD_ClearDisplay();
	LCD_Position(0, 0);
	LCD_PrintString("Congrats! :)");
	CyDelay(1000);
	LCD_Position(1, 0);
	LCD_PrintString("Youuu wonnn!!!");
	CyDelay(2000);
	LCD_ClearDisplay();
    PWM_WriteCompare1(600);
    PWM_WriteCompare2(600);
	smileyFace();
}

void fail(void)
{
	CyGlobalIntEnable;
	LCD_Position(0, 0);
	LCD_PrintString("You failed :(");
	CyDelay(1000);
	LCD_Position(1, 0);
	LCD_PrintString("Let's try again");
	CyDelay(2000);
	LCD_ClearDisplay();
	main();
}

char keypad(int row, int col)
{
	switch (row)
	{
		case 0x7:
			{
				switch (col)
				{
					case 0x7:
						return '1';
					case 0xB:
						return '2';
					case 0xD:
						return '3';
					case 0xE:
						return 'A';
				}
			}

		case 0xB:
			{
				switch (col)
				{
					case 0x7:
						return '4';
					case 0xB:
						return '5';
					case 0xD:
						return '6';
					case 0xE:
						return 'B';
				}
			}

		case 0xD:
			{
				switch (col)
				{
					case 0x7:
						return '7';
					case 0xB:
						return '8';
					case 0xD:
						return '9';
					case 0xE:
						return 'C';
				}
			}

		case 0xE:
			{
				switch (col)
				{
					case 0x7:
						return '*';
					case 0xB:
						return '0';
					case 0xD:
						return '#';
					case 0xE:
						return 'D';
				}
			}
	}

	return 0;
}

int assign(char value)
{
	switch (value)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case '*':
			return 14;
		case '#':
			return 15;
	}

	return 0;
}

const char *problem(int choice)
{
	switch (choice)
	{
		case 0:
			return "10 + 3";
		case 1:
			return "5 + 10";
		case 2:
			return "16 + 6";
		case 3:
			return "2 + 16";
		case 4:
			return "20 + 5";
		case 5:
			return "45 + 7";
		case 6:
			return "50 + 25";
		case 7:
			return "55 + 35";
		case 8:
			return "7 + 3";
		case 9:
			return "2 + 10";
		case 10:
			return "15 + 15";	
		case 11:
			return "7 + 16";	
		case 12:
			return "31 + 35";	
		case 13:
			return "79 + 10";
		case 14:
			return "20 + 22";	
		case 15:
			return "9 + 16";	
	}

	return 0;
}

int confirm(int choice, int n, char value)
{
	switch (choice)
	{
		case 0:
			switch (n)
			{
				case 0:
					if (value == '1')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '3')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 1:
			switch (n)
			{
				case 0:
					if (value == '1')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '5')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 2:
			switch (n)
			{
				case 0:
					if (value == '2')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '2') return 1;
			}

		case 3:
			switch (n)
			{
				case 0:
					if (value == '1')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '8')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 4:
			switch (n)
			{
				case 0:
					if (value == '2')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '5')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 5:
			switch (n)
			{
				case 0:
					if (value == '5')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '2')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 6:
			switch (n)
			{
				case 0:
					if (value == '7')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '5')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 7:
			switch (n)
			{
				case 0:
					if (value == '9')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '0')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 8:
			switch (n)
			{
				case 0:
					if (value == '1')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '0')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 9:
			switch (n)
			{
				case 0:
					if (value == '1')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '2')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 10:
			switch (n)
			{
				case 0:
					if (value == '3')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '0')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 11:
			switch (n)
			{
				case 0:
					if (value == '2')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '3')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 12:
			switch (n)
			{
				case 0:
					if (value == '6')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '6')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 13:
			switch (n)
			{
				case 0:
					if (value == '8')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '9')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 14:
			switch (n)
			{
				case 0:
					if (value == '4')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '4')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}

		case 15:
			switch (n)
			{
				case 0:
					if (value == '2')
					{
						return 1;
					}
					else
					{
						return 0;
					}

				case 1:
					if (value == '5')
					{
						return 1;
					}
					else
					{
						return 0;
					}
			}
	}

	return 0;
}

void mathGame(void)
{
	int col = 0;
	char value[17];
	int n = 0;
	int correct = 0;

	CyGlobalIntEnable;
	LCD_Start();
	LCD_Position(0, 0);
	LCD_PrintString("Addition Game");
	LCD_ClearDisplay();
	CyDelay(1000);

	bool complete = false;

	int choice = 0;
	bool assigned = false;

	while (1)
	{
		if (!assigned)
		{
			LCD_Position(0, 0);
			LCD_PrintString("Press a button");
            LCD_Position(1,0);
            LCD_PrintString("on the keypad");
			pinsRow_Write(0x7);
			if (pinsCol_Read() < 0xF)
			{
				col = pinsCol_Read();
				choice = assign(keypad(0x7, col));
				assigned = true;
				LCD_ClearDisplay();
				CyDelay(1000);
			}

			pinsRow_Write(0xB);
			if (pinsCol_Read() < 0xF)
			{
				col = pinsCol_Read();
				choice = assign(keypad(0xB, col));
				assigned = true;
				LCD_ClearDisplay();
				CyDelay(1000);
			}

			pinsRow_Write(0xD);
			if (pinsCol_Read() < 0xF)
			{
				col = pinsCol_Read();
				choice = assign(keypad(0xD, col));
				assigned = true;
				LCD_ClearDisplay();
				CyDelay(1000);
			}

			pinsRow_Write(0xE);
			if (pinsCol_Read() < 0xF)
			{
				col = pinsCol_Read();
				choice = assign(keypad(0xE, col));
				assigned = true;
				LCD_ClearDisplay();
				CyDelay(1000);
			}

			if (assigned)
			{
				LCD_Position(0, 0);
				LCD_PrintString("Password:");
				LCD_PrintString(problem(choice));
			}
		}
		else
		{
			bool check = false;
			pinsRow_Write(0x7);
			if (pinsCol_Read() < 0xF)
			{
				if (!complete)
				{
					col = pinsCol_Read();
					check = true;
					LCD_Position(1, n);
					value[0] = keypad(0x7, col);
                    value[1] = 0;
					if (confirm(choice, n, keypad(0x7, col)) == 1)
					{
						correct = correct + 1;
					}	//printing the character to the LCD for 2 seconds
					LCD_PrintString(value);
					CyDelay(1000);
					n = n + 1;
				}
			}

			pinsRow_Write(0xB);
			if (pinsCol_Read() < 0xF)
			{
				if (!check && !complete)
				{
					col = pinsCol_Read();
					check = true;
					LCD_Position(1, n);
					value[0] = keypad(0xB, col);
                    value[1] = 0;
					if (confirm(choice, n, keypad(0xB, col)) == 1)
					{
						correct = 1 + correct;
					}

					LCD_PrintString(value);
					CyDelay(1000);
					n = n + 1;
				}
			}

			pinsRow_Write(0xD);
			if (pinsCol_Read() < 0xF)
			{
				if (!check && !complete)
				{
					col = pinsCol_Read();
					check = true;
					LCD_Position(1, n);
					value[0] = keypad(0xD, col);
                    value[1] = 0;
					if (confirm(choice, n, keypad(0xD, col)) == 1)
					{
						correct = 1 + correct;
					}

					LCD_PrintString(value);
					CyDelay(1000);
					n = n + 1;
				}
			}

			pinsRow_Write(0xE);
			if (pinsCol_Read() < 0xF)
			{
				if (!check && !complete)
				{
					col = pinsCol_Read();
					check = true;
					LCD_Position(1, n);
					value[0] = keypad(0xE, col);
                    value[1] = 0;
					if (confirm(choice, n, keypad(0xE, col)) == 1)
					{
						correct = 1 + correct;
					}

					LCD_PrintString(value);
					CyDelay(1000);
					n = n + 1;
				}
			}

			if (n == 2 && correct == 2)
			{
				LCD_ClearDisplay();
				LCD_Position(0, 0);
				LCD_PrintString("Password");
				LCD_Position(1, 0);
				LCD_PrintString("is correct");
				CyDelay(1000);
				complete = true;
				mazeGame();
			}
			else if (n == 2 && correct != 2)
			{
				LCD_ClearDisplay();
				LCD_Position(0, 0);
				LCD_PrintString("Incorrect");
				LCD_Position(1, 0);
				LCD_PrintString("Password");
				CyDelay(1000);
				complete = true;
				fail();
			}
		}

		CyDelay(30);
	}
}

void mazeGame(void)
{
	CyGlobalIntEnable;						 //displaying instructions to LCD
	LCD_Position(0, 0);
	LCD_PrintString("Solve the maze");
	CyDelay(1000);
	LCD_Position(1, 0);
	LCD_PrintString("... NOW!!!");
	CyDelay(2000);
	LCD_ClearDisplay();
	int check = 1;
	for (;;)
	{
		uint8 Row = 0x80;
		int delay = 2;

		if (check == 1)					//check is level
		{
			Row_Write(~Row);				//scanning LED matrix, displaying first dot position
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0x7F);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())				//testing if the user input is correct for this position
			{
				Row_Write(0xFF);
				check = 2;				//rightButton is correct press, so go to next position 
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 2)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xBF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 3;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 3)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xBF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 4;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 2;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 4)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xDF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 5;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 5)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xEF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 6;
				CyDelay(1000);
			}
		}
		else if (check == 6)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xEF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 7;
				CyDelay(1000);
			}
		}
		else if (check == 7)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xEF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 8;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 8)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xF7);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 9;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 9)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFB);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 10;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 10)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFB);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 11;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 11)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFD);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 12;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 12)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFD);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 13;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 13)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFD);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			if (rightButton_Read())
			{
				Row_Write(0xFF);
				check = 14;
				CyDelay(1000);
			}
			else if (upButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
			else if (downButton_Read())
			{
				Row_Write(0xFF);
				check = 0;
				CyDelay(1000);
			}
		}
		else if (check == 14)
		{
			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x03);
			Red_Write(0xFE);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x72);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xD6);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x1C);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0x00);
			Red_Write(0xFF);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);
			ledWrite();
		}
		else if (check == 0)
		{
			Row_Write(~Row);
			Blue_Write(0xFF);
			Red_Write(0x00);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xFF);
			Red_Write(0x00);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xFF);
			Red_Write(0x00);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xFF);
			Red_Write(0x00);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xFF);
			Red_Write(0x00);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xFF);
			Red_Write(0x00);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xFF);
			Red_Write(0x00);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);

			Row_Write(~Row);
			Blue_Write(0xFF);
			Red_Write(0x00);
			Green_Write(0xFF);
			Row = Row >> 1;
			CyDelay(delay);
			fail();
		}
	}
}

void ledWrite(void)
{
	LCD_Position(0, 0);
	LCD_PrintString("Stop on the line");
	CyDelay(1000);
	LCD_Position(1, 0);
	LCD_PrintString("... goodluck");
	CyDelay(2000);
	LCD_ClearDisplay();
	int rand = 4;
	for (;;)
	{
		Row_Write(0x00);	//turning on all the mosfets
		Red_Write(0xEF);	//turning on LED strip by pulling down 4th row 1110 1111
		Green_Write(0xFF);
		Blue_Write(0xFF);
		uint8 index = 0x80;
		for (int i = 0; i < 8; i = i + 1)
		{
			if (rightButton_Read() == 1 && rand != i)	//pressing the button on the wrong column
			{
				Red_Write(0x00);	//all red LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
			}

			if (rightButton_Read() == 1 && rand == i)	//pressing the button on the correct column 
			{
				Green_Write(0x00);	//all blue LEDs light up 
				CyDelay(1000);
				Red_Write(0xEF);
				Green_Write(0xFF);
				ledWriteLevel2();
			}

			Blue_Write(~index);	//turning on single blue column 
			index = index >> 1;	//shifting column index over one bit so that blue column to right of current one turns on next
			CyDelay(200);
		}

		index = 0x01;
		for (int i = 9; i >= 2; i = i - 1)
		{
			if (rightButton_Read() == 1 && rand != i)	//pressing the button on the wrong column
			{
				Red_Write(0x00);	//all red LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
			}

			if (rightButton_Read() == 1 && rand == i)	//pressing the button on the correct column 
			{
				Green_Write(0x00);	//all blue LEDs light up 
				CyDelay(1000);
				Red_Write(0xEF);
				Green_Write(0xFF);
				ledWriteLevel2();
			}

			Blue_Write(~index);	//turning on single blue column           
			index = index << 1;	//shifting column index over one bit so that blue column to right of current one turns on next
			CyDelay(200);
		}
	}
}

void ledWriteLevel2(void)
{
	LCD_Position(0, 0);
	LCD_PrintString("FASTER");
	CyDelay(1000);
	LCD_ClearDisplay();
	int rand = 4;
	for (;;)
	{
		Row_Write(0x00);	//turning on all the mosfets
		Red_Write(0xEF);	//turning on LED strip by pulling down 4th row 1110 1111
		Green_Write(0xFF);
		Blue_Write(0xFF);
		uint8 index = 0x80;
		for (int i = 0; i < 8; i = i + 1)
		{
			if (rightButton_Read() == 1 && rand != i)	//pressing the button on the wrong column
			{
				Red_Write(0x00);	//all red LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
			}

			if (rightButton_Read() == 1 && rand == i)	//pressing the button on the correct column 
			{
				Green_Write(0x00);	//all blue LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
				Green_Write(0xFF);
				ledWriteLevel3();
			}

			Blue_Write(~index);	//turning on single blue column 
			index = index >> 1;	//shifting column index over one bit so that blue column to right of current one turns on next
			CyDelay(100);
		}

		index = 0x01;
		for (int i = 9; i >= 2; i = i - 1)
		{
			if (rightButton_Read() == 1 && rand != i)	//pressing the button on the wrong column
			{
				Red_Write(0x00);	//all red LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
			}

			if (rightButton_Read() == 1 && rand == i)	//pressing the button on the correct column 
			{
				Green_Write(0x00);	//all blue LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
				Green_Write(0xFF);
				ledWriteLevel3();
			}

			Blue_Write(~index);	//turning on single blue column           
			index = index << 1;	//shifting column index over one bit so that blue column to right of current one turns on next
			CyDelay(100);
		}
	}
}

void ledWriteLevel3(void)
{
	LCD_Position(0, 0);
	LCD_PrintString("EVEN FASTER");
	CyDelay(1000);
	LCD_ClearDisplay();
	int rand = 4;
	for (;;)
	{
		Row_Write(0x00);	//turning on all the mosfets
		Red_Write(0xEF);	//turning on LED strip by pulling down 4th row 1110 1111
		Green_Write(0xFF);
		Blue_Write(0xFF);
		uint8 index = 0x80;
		for (int i = 0; i < 8; i = i + 1)
		{
			if (rightButton_Read() == 1 && rand != i)	//pressing the button on the wrong column
			{
				Red_Write(0x00);	//all red LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
			}

			if (rightButton_Read() == 1 && rand == i)	//pressing the button on the correct column 
			{
				Green_Write(0x00);	//all blue LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
				Green_Write(0xFF);
				servo();
			}

			Blue_Write(~index);	//turning on single blue column 
			index = index >> 1;	//shifting column index over one bit so that blue column to right of current one turns on next
			CyDelay(60);
		}

		index = 0x01;
		for (int i = 9; i >= 2; i = i - 1)
		{
			if (rightButton_Read() == 1 && rand != i)	//pressing the button on the wrong column
			{
				Red_Write(0x00);	//all red LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
			}
			else if (rightButton_Read() == 1 && rand == i)	//pressing the button on the correct column 
			{
				Green_Write(0x00);	//all blue LEDs light up 
				CyDelay(500);
				Red_Write(0xEF);
				Green_Write(0xFF);
				servo();
			}

			Blue_Write(~index);	//turning on single blue column           
			index = index << 1;	//shifting column index over one bit so that blue column to right of current one turns on next
			CyDelay(60);
		}
	}
}

void servo(void)
{
 	PWM_Start();    		//period of 20ms
    Clock_Start();			//initializing clock, ADCs, and PWMs
   	ADC1_Start();
   	ADC2_Start();
    ADC1_StartConvert();
    ADC2_StartConvert();
    
    PWM_WriteCompare1(600);		//600 is position at 0 degrees for these servos
    PWM_WriteCompare2(600);		//setting both servo positions to 0 degrees

   	uint16 mappedVal1 = 0;	//variable to map ADC1  value to 600-2600
    uint16 mappedVal2 = 0;		//variable to map ADC2 value to 600-2600
    uint16 percentVal1 = 0;		//variable to map ADC1  value to 0-100
    uint16 percentVal2 = 0;		//variable to map ADC2  value to 0-100
    char decimal[17];
    
    LCD_Start();				//displaying instructions
    LCD_ClearDisplay();
	LCD_Position(0, 0);
	LCD_PrintString("Twist of Fate");
    CyDelay(1000);
    LCD_Position(1,0);
    LCD_PrintString("Turn the knobs..");
    CyDelay(4000);
	LCD_ClearDisplay();
	CyDelay(1000);
    LCD_Position(0,0);
    LCD_PrintString("SLOWLY...");
    CyDelay(1000);
    

   	 for(;;)
    	{
       		mappedVal1 = (2000 * ADC1_GetResult16()) / 4095 + 600;      //getting ADC1 result (0-4095), mapping to 600-2600
        	mappedVal2 = (2000 * ADC2_GetResult16()) / 4095 + 600;	        //getting ADC2 result (0-4095), mapping to 600-2600
            
            percentVal1 = (100 * ADC1_GetResult16()) / 4095;		//getting ADC1 result (0-4095), mapping to 0-100
            percentVal2 = (100 * ADC2_GetResult16()) / 4095;		//getting ADC2 result (0-4095), mapping to 0-100
            
            LCD_Position(0,0);
            sprintf(decimal, "Value 1 = %d%%", percentVal1);
            LCD_PrintString(decimal);
            LCD_Position(1,0);
            sprintf(decimal, "Value 2 = %d%%", percentVal2); 
            LCD_PrintString(decimal); 
       		PWM_WriteCompare1(mappedVal1);
       		PWM_WriteCompare2(mappedVal2);
            

            
        if (percentVal1 == 100 && percentVal2 == 100)		//checking when both potentiometers are turned all the way
        {
            CyDelay(500);
            win();    
        }
        CyDelay(50);
        
	}
}



