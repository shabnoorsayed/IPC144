//==============================================
// Name:           Shabnoor Sayed
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>

int main(){

    int loonies; 
    int quarters;
    int cash;
    double amount = 0.0;
    float balanceAmountLoonies;
    float balanceAmountQuarters;

    printf("Please enter the amount to be paid: $");
    scanf("%lf", &amount);
    cash = amount * 100 + 0.5;
    loonies = cash / 100;
    cash = cash % 100;
    balanceAmountLoonies = cash / 100.0;
    quarters = cash / 25;
    cash = cash % 25;
    balanceAmountQuarters = cash / 100.0;

    printf("Loonies required: %d, balance owing $%.2f", loonies, balanceAmountLoonies);
    printf("\n");
    printf("Quarters required: %d, balance owing $%.2f", quarters, balanceAmountQuarters);
    printf("\n");
    return 0;
}