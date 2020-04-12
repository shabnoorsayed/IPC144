//==============================================
// Name:           Shabnoor Sayed
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>

int main(void) {

	int i, numDays;
	int high[10];
	int low[10];


	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &numDays);
	printf("\n");


	while (numDays < 3 || numDays > 10)
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &numDays);
		printf("\n");
	}

	for (i = 0; i < numDays; i++)
	{
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);

		while (high[i] > 40 || high[i] < -40 || low[i] > 40 || low[i] < -40 || high[i] < low[i])
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			
			printf("Day %d - High: ", i + 1);

			scanf("%d", &high[i]);

			printf("Day %d - Low: ", i + 1);
			scanf("%d", &low[i]);
		}

	}

	printf("\n");
	printf("Day  Hi  Low\n");
	

	for (i = 0; i < numDays; i++)
	{
		printf("%d    %d    %d\n", i + 1, high[i], low[i]);
	}
	return 0;


}
