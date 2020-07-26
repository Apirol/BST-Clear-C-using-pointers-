#include <stdio.h>
#include <conio.h>
#include "Header.h"
#include <locale.h>

enum operation { CMD_INPUT = 1, CMD_STRAIGHT, CMD_BACK, CMD_REKURS, CMD_TERMINAL, CMD_EXIT };

int main()
{
	setlocale(LC_CTYPE, "Rus");
	btree *b = NULL;
	int m, n, exitFlag = 0, counter = 0;
	do
	{
		printf_s("<1> - ��������� ������� � ������ \n");
		printf_s("<2> - ������ ����� ������ \n");
		printf_s("<3> - �������� ����� ������ \n");
		printf_s("<4> - ������ ����� ������ � ������� �������� \n");
		printf_s("<5> - �������� ����� ������ \n");
		printf_s("<6> - ����� \n");
		int repeatFlag = 0;
		do
		{
			printf_s("������� ����� ������� (�� 1 �� 4) \n");
			if (!scanf_s("%d", &n))
			{
				printf_s("������ \n");
				_getch();
				return 0;
			}
			switch (n)
			{
			case CMD_INPUT: printf_s("������� �������: ");
				scanf_s("%d", &m);
				input(b, m);
				break;
			case CMD_STRAIGHT: straight(b, counter);
				printf_s("\n���������� �������: ");
				printf_s("%d\n", counter);
				exitFlag = 1;
				break;
			case CMD_BACK: back(b, counter);
				printf_s("\n���������� �������: ");
				printf_s("%d \n", counter);
				exitFlag = 1;
				break;
			case CMD_REKURS: rekurs(b, counter);
				printf_s("\n���������� �������: ");
				printf_s("%d", counter);
				exitFlag = 1;
				break;
			case CMD_TERMINAL: terminal(b, counter);
				printf_s("\n���������� �������: ");
				printf_s("%d\n", counter);
				exitFlag = 1;
				break;
			case CMD_EXIT: exitFlag = 1;
				break;
			default: printf_s("������ ����� �������� \n");
				repeatFlag = 1;
				break;
			}
		} while (!exitFlag && !repeatFlag);
	} while (!exitFlag);
	_getch();
}