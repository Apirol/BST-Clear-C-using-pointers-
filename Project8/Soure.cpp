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
		printf_s("<1> - поместить элемент в дерево \n");
		printf_s("<2> - прямой обход дерева \n");
		printf_s("<3> - обратный обход дерева \n");
		printf_s("<4> - прямой обход дерева с помощью рекурсии \n");
		printf_s("<5> - концевой обход дерева \n");
		printf_s("<6> - выход \n");
		int repeatFlag = 0;
		do
		{
			printf_s("Введите номер команды (от 1 до 4) \n");
			if (!scanf_s("%d", &n))
			{
				printf_s("Ошибка \n");
				_getch();
				return 0;
			}
			switch (n)
			{
			case CMD_INPUT: printf_s("Введите элемент: ");
				scanf_s("%d", &m);
				input(b, m);
				break;
			case CMD_STRAIGHT: straight(b, counter);
				printf_s("\nКоличество листьев: ");
				printf_s("%d\n", counter);
				exitFlag = 1;
				break;
			case CMD_BACK: back(b, counter);
				printf_s("\nКоличество листьев: ");
				printf_s("%d \n", counter);
				exitFlag = 1;
				break;
			case CMD_REKURS: rekurs(b, counter);
				printf_s("\nКоличество листьев: ");
				printf_s("%d", counter);
				exitFlag = 1;
				break;
			case CMD_TERMINAL: terminal(b, counter);
				printf_s("\nКоличество листьев: ");
				printf_s("%d\n", counter);
				exitFlag = 1;
				break;
			case CMD_EXIT: exitFlag = 1;
				break;
			default: printf_s("Ошибка ввода операции \n");
				repeatFlag = 1;
				break;
			}
		} while (!exitFlag && !repeatFlag);
	} while (!exitFlag);
	_getch();
}