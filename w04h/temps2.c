//==============================================
// Name:           Shabnoor Sayed
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Place your code below
/******************************************************************************

							Online C Compiler.
				Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main(void)
{
	int nums, i, dayHigh, dayLow, days,t; 
	int totalHigh = 0; 
	int totalLow = 0;
	double total, average;
	int high[10];
	int low[10];
	int highTemp = -40;
	int lowTemp = 40;

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &nums);
	printf("\n");

	while (nums < 3 || nums>10) {

		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &nums);
		printf("\n");
	}

	for (i = 0; i < nums; i++) {

		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);

		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);

		while (high[i] > 40 || high[i] < -40 || low[i] > 40 || low[i] < -40 || high[i] < low[i])
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");
			printf("Day %d - High: ", i + 1);

			scanf("%d", &high[i]);

			printf("Day %d - Low: ", i + 1);
			scanf("%d", &low[i]);
			
		}

	}
	printf("\n");
	printf("Day   Hi   Low\n");

	for (i = 0; i < nums; i++) {

		printf("%d    ", i + 1);
		printf("%d    ", high[i]);
		printf("%d\n", low[i]);

	}
	printf("\n");
	for (i = 0; i < nums; i++) {

		if (high[i] > highTemp) {

			dayHigh = i + 1;
			highTemp = high[i];

		}
		if (low[i] < lowTemp) {

			dayLow = i + 1;
			lowTemp = low[i];

		}
	}

	printf("highest temp: %d on day: %d\n", highTemp, dayHigh);
	printf("lowest temp: %d on day: %d\n", lowTemp, dayLow);
	printf("\n");
	printf("Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
	scanf("%d", &days);
	printf("\n");
	while (days >= 0) {

		while (days == 0 || days > 5) {
		
			printf("Invalid entry, please enter a number between 1 and 5, inclusive: ");
			scanf("%d", &days);
			
		}
		while (days <= 5 && days > 0) {

			for (i = 0; i < days; i++) {

				totalHigh += high[i];
				totalLow += low[i];
				total = (double)totalHigh + totalLow;
				t = days * 2;
				average = total /t;
			}

			printf("\n");
			printf("The average temperature up to day %d is: %.2lf\n", days, average);
			printf("\n");
			printf("Enter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", nums);
			scanf("%d", &days);
			totalHigh = 0;
			totalLow = 0;
			average = 0;
		}

	}
	printf("\n");
	printf("Goodbye!\n");
}
