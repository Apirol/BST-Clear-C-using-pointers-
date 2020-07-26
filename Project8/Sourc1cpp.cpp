#include <stdio.h>
#include <conio.h>
#include "Header.h"
#include <stack>

using namespace std;

void input(btree *&b, int m)
{
	if (b == NULL)
	{
		b = new btree;
		b->elem = m;
		b->left = b->right = NULL;
	}
	else
	{
		if (m < b->elem)
		{
			if (b->left == NULL)
			{
				b->left = new btree;
				b->left->left = b->left->right = NULL;
				b->left->elem = m;
			}
			else
				input(b->left, m);
		}
		if (m > b->elem)
			if (b->right == NULL)
			{
				b->right = new btree;
				b->right->left = b->right->right = NULL;
				b->right->elem = m;
			}
			else
				input(b->right, m);
	}
}

void straight(btree *&b, int &counter)
{
	if (b)
	{
		stack <btree> L;
		while (b)
		{
			printf_s("%d ", b->elem);
			if (b->left != NULL && b->right != NULL)
			{
				L.push(*b->right);
				b = b->left;
			}
			else if (b->left == NULL && b->right == NULL)
			{
				if (!L.empty())
				{
					*b = L.top();
					L.pop();
					++counter;
				}
				else
				{
					++counter;
					b = NULL;
				}
			}
			else if (b->left != NULL)
				b = b->left;
			else
				b = b->right;
		}
	}
	else
		printf_s("Дерево пусто\n");
}

void rekurs(btree *&b, int &counter)
{
	if (b)
	{
		printf_s("%d ", b->elem);
		rekurs(b->left, counter);
		rekurs(b->right, counter);
	}
	else
		++counter;
}



void terminal2(btree *&b, int &counter)
{
	int exitFlag = 1;
	stack <btree> S;
	while (b)
	{
		exitFlag = 1;
		while (exitFlag)
		{
			if (b->left != NULL && b->right != NULL)
			{
				S.push(*b);
				b = b->left;
			}
			else if (b->left == NULL && b->right == NULL)
			{
				++counter;
				printf_s("%d ", b->elem);
				exitFlag = 0;
			}
			else if (b->left != NULL)
			{
				S.push(*b);
				b = b->left;
			}
			else
			{
				printf_s("%d ", b->elem);
				b = b->right;
			}
		}
		if (!S.empty())
		{
			*b = S.top();
			S.pop();
			S.push(*b);
			b = b->right;
			printf_s("%d ", b->elem);
		}
	}
}

void terminal(btree *&b, int &counter)
{
	int exitFlag = 1;
	stack <btree> S;
	exitFlag = 1;
	while (exitFlag)
	{
		while (b->left != NULL && b->right != NULL)
		{
			S.push(*b);
			S.push(*b->right);
			b = b->left;
		}
		if (!S.empty())
		{
			++counter;
			printf_s("%d ", b->elem);
			*b = S.top();
			S.pop();
			if (b->left != NULL && b->right != NULL)
			{
				printf_s("%d ", b->elem);
				b = NULL;
				exitFlag = 0;
			}
		}
		else
		{
			++counter;
			printf_s("%d ", b->elem);
			exitFlag = 0;
			b = NULL;
		}
	}
}

void back(btree *&b, int &counter)
{
	int exitFlag = 1;
	stack <btree> S;
	while (b)
	{
		exitFlag = 1;
		while (exitFlag)
		{
			if (b->left != NULL && b->right != NULL)
			{
				S.push(*b);
				b = b->left;
			}
			else if (b->left == NULL && b->right == NULL)
			{
				++counter;
				printf_s("%d ", b->elem);
				exitFlag = 0;
			}
			else if (b->left != NULL)
			{
				S.push(*b);
				b = b->left;
			}
			else
			{
				printf_s("%d ", b->elem);
				b = b->right;
			}
		}
		if (!S.empty())
		{
			*b = S.top();
			S.pop();
			printf_s("%d ", b->elem);
			if (b->right != NULL)
				b = b->right;
			else
			{
				*b = S.top();
				S.pop();
				printf_s("%d ", b->elem);
				if (b->right != NULL)
					b = b->right;
				else
					b = NULL;
			}
		}
		else
			b = NULL;
	}
}
