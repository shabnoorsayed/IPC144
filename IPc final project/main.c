/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)Shabnoor Sayed             ssayed10@myseneca.ca
   2)
   3)

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#include "file_helper.h"
#include <ctype.h> 
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define MAXCHAR 5000

struct RiderInfo riders[MAXCHAR];
struct RiderInfo sortedRiders[MAXCHAR];


char* getTimmer(double time) {

    double totalMins = time * 60;
    int hour = totalMins / 60;
    int min = (int)totalMins % 60;
    static char timmer[6];
    sprintf(timmer, "%d:%02d", hour, min);
    return timmer;
}

char* ageGroup(int age) {
   

    if (age >= 16 && age <= 20) {
        return "Junior";
    }
    else if (age >= 21 && age <= 34) {
        return "Adult";
    }
    else if (age > 34) {
        return "Senior";
    }
}


void getRiders() {

    FILE* fp;
    char str[MAXCHAR];
    char* filename = "data.txt";

    fp = fopen(filename, "r");

    int result = 0;
    int i = 0;
    while (result == 0) {
        result = readFileRecord(fp, &sortedRiders[i]);
        i++;
    }
}

void sortRiders()
{
    int i, j;
    struct RiderInfo temp;
    
    //sortedRiders = malloc(MAXCHAR * sizeof(struct RiderInfo));
    //memcpy(sortedRiders, riders, sizeof sortedRiders);

    int size = sizeof(sortedRiders) / sizeof(sortedRiders[0]);
    
    for (i = 0; i < size - 1 && sortedRiders[i].age != 0; i++)
    {
        for (j = 0; j < (size - 1 - i) && sortedRiders[j].age != 0 && sortedRiders[j+1].age != 0; j++)
        {
            double totalTime = sortedRiders[j].finishTime - sortedRiders[j].startTime;
            double totalTimeTwo = sortedRiders[j + 1].finishTime - sortedRiders[j + 1].startTime;
            if (totalTime > totalTimeTwo)
            {
                temp = sortedRiders[j];
                sortedRiders[j] = sortedRiders[j + 1];
                sortedRiders[j + 1] = temp;
            }
        }
    }
}

void getTopRiderByCategory(char inputCategory[2]) {

    getRiders();
    sortRiders();
    char upper[2];
    upper[0] =  toupper(inputCategory[0]);
    upper[1] = '\0';
   
   
    int count = 0;
    int check = 0;
    for (int i = 0; i < MAXCHAR; i++) {
        if (strcmp(sortedRiders[i].raceLength, upper) == 0 && count <3 && sortedRiders[i].withdrawn == 0) {
            double totalTime = sortedRiders[i].finishTime - sortedRiders[i].startTime;
            printf("%s          %s       %s", sortedRiders[i].name, ageGroup(sortedRiders[i].age), getTimmer(totalTime));
            printf("\n");
            count++;
            check = 1;
        }
    }
    if (!check) {
        printf("\n");
        printf("*********NOT AWARDED********\n");
    }
}

void getAllRiderByCategory(char inputCategory[2]) {
    getRiders();
    sortRiders();

    char upper[2];
    upper[0] = toupper(inputCategory[0]);
    upper[1] = '\0';

    for (int i = 0; i < MAXCHAR; i++) {
        if (strcmp(sortedRiders[i].raceLength, upper) == 0) {
            double totalTime = sortedRiders[i].finishTime - sortedRiders[i].startTime;
            printf("%s       %s      %s      %s", sortedRiders[i].name, ageGroup(sortedRiders[i].age), getTimmer(totalTime), sortedRiders[i].withdrawn ? "Yes":"No");
            printf("\n");
        }
    }

}

void getBottomRiderByCategory(char inputCategory[2]) {

    getRiders();
    sortRiders();
    char upper[2];
    upper[0] = toupper(inputCategory[0]);
    upper[1] = '\0';

    int count = 0;
    for (int i = MAXCHAR-1; i >= 0; i--) {
        if (strcmp(sortedRiders[i].raceLength, upper) == 0 && count < 3 && sortedRiders[i].withdrawn == 0 && sortedRiders[i].age != 0) {
            double totalTime = sortedRiders[i].finishTime - sortedRiders[i].startTime;
            printf("%s          %s          %s", sortedRiders[i].name, ageGroup(sortedRiders[i].age), getTimmer(totalTime));
            printf("\n");
            count++;
        }
    }
}

void getWinners() {

    getRiders();
    sortRiders();
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    
    for (int i = 0; i < MAXCHAR && sortedRiders[i].age != 0;i++) {
        if ((strcmp(sortedRiders[i].raceLength ,"S") == 0 || strcmp(sortedRiders[i].raceLength, "s") == 0) && count1 <1 && sortedRiders[i].withdrawn == 0) {
            double totalTime = sortedRiders[i].finishTime - sortedRiders[i].startTime;
            printf("%s      %s      %s", sortedRiders[i].name, ageGroup(sortedRiders[i].age), getTimmer(totalTime));
            printf("\n");
            count1++;
        }else if ((strcmp(sortedRiders[i].raceLength, "M") == 0 || strcmp(sortedRiders[i].raceLength, "m") == 0) && count2 < 1 && sortedRiders[i].withdrawn == 0) {
            double totalTime = sortedRiders[i].finishTime - sortedRiders[i].startTime;
            printf("%s       %s         %s", sortedRiders[i].name, ageGroup(sortedRiders[i].age), getTimmer(totalTime));
            printf("\n");
            count2++;
        }
        else if ((strcmp(sortedRiders[i].raceLength, "L") == 0 || strcmp(sortedRiders[i].raceLength, "l") == 0) && count3 < 1 && sortedRiders[i].withdrawn == 0) {
            double totalTime = sortedRiders[i].finishTime - sortedRiders[i].startTime;
            printf("%s      %s      %s", sortedRiders[i].name, ageGroup(sortedRiders[i].age), getTimmer(totalTime));
            printf("\n");
            count3++;
        }
    }

}

int main(void)
{
 
    int x, a = 1;
    char inputCategory[2] = { NULL };

    while (a == 1)
    {
        x = displayMenu();
        switch (x) 
        {
        case 0:
            a = 0;
            printf("bye\n");
            break;
        case 1:
            printf("Which Category (S,M L): ");
            scanf("%s", &inputCategory);
            printf("\n");
            printf("Rider     Age Group    Time");
            printf("\n");
            printf("-----------------------------");
            printf("\n");
            getTopRiderByCategory(inputCategory);
            break;
        case 2:
            printf("Which Category (S,M L): ");
            scanf("%s", &inputCategory);
            printf("\n");
            printf("Rider           Age Group     Time         Withdraw");
            printf("\n");
            printf("-----------------------------");
            printf("\n");
            getAllRiderByCategory(inputCategory);
            break;
        case 3:
            printf("Which Category (S,M L): ");
            scanf("%s", &inputCategory);
            printf("\n");
            printf("Rider           Age Group         Time");
            printf("\n");
            printf("-----------------------------");
            printf("\n");
            getBottomRiderByCategory(inputCategory);
            break;
        case 4:
            printf("\n");
            printf("Rider           Age Group         Time");
            printf("\n");
            printf("-----------------------------");
            printf("\n");
            getWinners();
            break;
        }
    }
    
	return 0;
}