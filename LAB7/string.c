#include"string.h"
#include <stdio.h>
#include <stdlib.h>

#define KB 1024


void symbolCheker(char* symbol)
{
	while ((scanf_s("%c", &*symbol, 1)) != 1 || getchar() != '\n')
	{
		printf("Input correct symbol:");
		rewind(stdin);
	}
}



void correctNumber(int* num, char* str)
{
	while ((scanf_s("%d", &*num)) != 1 || getchar() != '\n' || *num<1 || *num > numOfWords(str, len(str)))
	{
		if (*num > numOfWords(str, len(str)))
			printf("There are only %d words.Input correct number:", numOfWords(str, len(str)));
		else
			printf("Intput correct number:");
		rewind(stdin);
	}
}

char* memory()
{
	char* str;
	str = (char*)calloc(KB, sizeof(char));
	return str;
}

int len(char* str)
{
	int i = 0, n;
	while (*(str + i) != '\n' && *(str + i) != '\0')
	{
		i++;
	}
	n = i;
	return n;

}

void inputStr(char** str, int variant)
{
	switch (variant)
	{
	case 1:
		do {
			printf("Input string: ");
			rewind(stdin);
			fgets(*str, KB, stdin);
			rewind(stdin);
		} while (len(*str) < 1 || numOfWords(*str, len(*str)) < 1);
			char* storer = (char*)realloc(*str, (len(*str) + 2) * sizeof(char));
			if (storer != NULL)
			{
				*str = storer;
			}
		break;
	case 2:
		do {
			printf("Input first string: ");
			rewind(stdin);
			fgets(*str, KB, stdin);
			rewind(stdin);
		} while (len(*str) < 1);
		storer = (char*)realloc(*str, (len(*str) + 2) * sizeof(char));
		if (storer != NULL)
		{
			*str = storer;
		}
		break;
	case 3:
		do {
			printf("Input string that you want to add before this symbol: ");
			rewind(stdin);
			fgets(*str, KB, stdin);
			rewind(stdin);
		} while (len(*str) < 1);
		storer = (char*)realloc(*str, (len(*str) + 2) * sizeof(char));
		if (storer != NULL)
		{
			*str = storer;
		}
		break;
	}
}

void revirse(char* str, int start, int end)
{
	char storer;
	while (end > start)
	{
		storer = *(str + end);
		*(str + end) = *(str + start);
		*(str + start) = storer;
		end--;
		start++;
	}

}

int numOfWords(char* str, int size)
{
	int n_worlds = 0;
	for (int i = 0; i < size; i++)
	{
		if (((*(str + i) >= 'A' && *(str + i) <= 'Z') || (*(str + i) >= 'a' && *(str + i) <= 'z')) && (!((*(str + i + 1) >= 'A' && *(str + i + 1) <= 'Z') || (*(str + i + 1) >= 'a' && *(str + i + 1) <= 'z'))))
		{
			n_worlds++;
		}
	}
	return n_worlds;
}

void revK(char* str, int k)
{
	int cheker = 0, start = 0, end = 0;
	int size = len(str);
	for (int i = 0; i < size; i++)
	{
		if (((*(str + i) >= 'A' && *(str + i) <= 'Z') || (*(str + i) >= 'a' && *(str + i) <= 'z')) && (!((*(str + i + 1) >= 'A' && *(str + i + 1) <= 'Z') || (*(str + i + 1) >= 'a' && *(str + i + 1) <= 'z'))))
		{
			cheker++;
		}
		if (cheker == k)
		{
			end = i;
			for (int j = end; j >= 0; j--)
			{
				if ((*(str + j) >= 'A' && *(str + j) <= 'Z') || (*(str + j) >= 'a' && *(str + j) <= 'z') && (!((*(str + j - 1) >= 'A' && *(str + j - 1) <= 'Z') || (*(str + j - 1) >= 'a' && *(str + j - 1) <= 'z'))))
				{
					start = j;
					break;
				}
			}
			break;
		}
	}
	revirse(str, start, end);
}

void addString(char** str1, char** str2, char symbol)
{
	int size1 = len(*str1);
	int size2 = len(*str2);
	for (int i = 0; i < size1; i++)
	{
		if ((*str1 + i) != NULL)
		{
			if (*(*str1 + i) == symbol)
			{
				char *storer = (char*)realloc(*str1, (size1 + size2 + 2) * sizeof(char));
				if (storer != NULL)
				{
					*str1 = storer;
				}
				size1 += (size2 + 2);
				for (int j = size1 - 1; j > i + size2 - 1; j--)
				{
					*(*str1 + j) = *(*str1 + j - size2);
				}
				for (int j = i, k = 0; k < size2; j++, k++)
				{
					if ((*str2) != NULL)
					{
						*(*str1 + j) = *(*str2 + k);
					}
				}
				i += size2;
			}
		}
	}
}

void menuCorrect(int* task)
{
	while ((scanf_s("%d", &*task)) != 1 || *task < 1 || *task>3 || getchar() != '\n')
	{
		printf("Make right choise(1-3):");
		rewind(stdin);
	}
}

void taskFirst(void)
{
	char* str = memory();
	int word_number = 0;
	inputStr(&str, 1);
	printf("Chooise number of word , that you want to reverse:");
	correctNumber(&word_number, str);
	revK(str, word_number);
	printf("\nResult: ");
	fputs(str, stdout);
	free(str);
}

void taskSecond(void)
{
	char symbol;
	char* str1 = memory();
	inputStr(&str1, 2);
	printf("Input symbol:");
	symbolCheker(&symbol);
	char* str2 = memory();
	inputStr(&str2, 3);
	addString(&str1, &str2, symbol);
	printf("\nResult: ");
	fputs(str1, stdout);
	free(str1);
	free(str2);
}