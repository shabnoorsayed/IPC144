//==============================================
// Name:           Shabnoor Sayed
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:
#include <stdio.h>
#define NUMS 3


int main(){
     
    int high[4];
    int low[4];
    int i;
    printf("---=== IPC Temperature Analyzer ===---\n");

    for (i = 0; i < NUMS; i++){
        printf("Enter the high value for day %d: ", i + 1);
        scanf("%d", &high[i]);
        printf("\n");
        printf("Enter the low value for day %d: ", i + 1);
        scanf("%d", &low[i]);
        while (high[i] > low[i] && high[i]<40 && low[i] >-40){
            break;
        }

        printf("\n");

        while (high[i] < low[i] || high[i]>40 || low[i]<-40){
            printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
            printf("\n");
            printf("Enter the high value for day %d: ", i + 1);
            scanf("%d", &high[i]);
            printf("\n");
            printf("Enter the low value for day %d: ", i + 1);
            scanf("%d", &low[i]);

            while (high[i] > low[i] && high[i]<40 && low[i]>-40){
                break;
            }
            printf("\n");
        }
    }
    return 0;
}
