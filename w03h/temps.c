//==============================================
// Name:           Shabnoor Sayed
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 4

int main(void) {
	float mean, meanHigh, meanLow;
	int high, low, i;
	int maxTemp = -41;
	int minTemp = 41;
	int highest = 0;
	int lowest = 0;
	int totalHigh = 0;
	int totalLow = 0;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 1; i <= NUMS; i++) {
		do {

			printf("Enter the high value for day %d: ", i);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i);
			scanf("%d", &low);
			printf("\n");

			if (high > 40 || low < -40 || high < low) {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				printf("\n");

			}
			else {

				totalHigh += high;
				totalLow += low;
				meanHigh = totalHigh / 4.0;
				meanLow = totalLow / 4.0;
				mean = (totalHigh + totalLow) / (float)(NUMS * 2);

			}
			if (maxTemp < high) {
				
				maxTemp = high;
				highest = i;

			}
			if (minTemp > low) {
				
				minTemp = low;
				lowest = i;

			}
		} while (high > 40 || low < -40 || high < low);
	}
	
	printf("The average (mean) LOW temperature was: %.2f\n", meanLow);
	printf("The average (mean) HIGH temperature was: %.2f\n", meanHigh);
	printf("The average (mean) temperature was: %.2f\n", mean);
	printf("The highest temperature was %d, on day %d\n", maxTemp, highest);
	printf("The lowest temperature was %d, on day %d\n", minTemp, lowest);
	return 0;
}
