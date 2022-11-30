#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void taskFirst(void);

void taskSecond(void);

int main()
{
	int choise=0,task_choise=0;
	void (**menu)() = (void(**)())calloc(2, sizeof(void(*)()));
	menu[0] = taskFirst;
	menu[1] = taskSecond;
	do {
		printf("  Menu:\n");
		printf("1.Reverse k word.\n2.There are symbol C and strings S,S0.Before every C-symbol input S0.\n3.Exit.\nYour choise:");
		menuCorrect(&task_choise);
		system("cls");
		if (task_choise == 3)
			return 0;
		menu[(task_choise-1)]();
		printf("\nDo you want to continue?(Yes-1/No-0):");
		scanf_s("%d", &choise);
		system("cls");
	} while (choise == 1);
	return 0;
}