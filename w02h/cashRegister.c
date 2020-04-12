//==============================================
// Name:           Shabnoor Sayed
// Student Number: 133949194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications

#include <stdio.h>

int main(){

    // declared all the required variables//
    int loonies; 
    int quarters; 
    int dimes; 
    int nickels; 
    int pennies; 
    int cash;
    double amount = 0.0;
    float balanceAmountLoonies;
    float balanceAmountQuarters; 
    float balanceAmountDimes; 
    float balanceAmountNikels;
    float balanceAmountPennies; 
    float GST;
    float priceTax;


    printf("Please enter the amount to be paid: $");
    scanf("%lf", &amount);   // ask for user input to get the value of amount


    GST = (amount * 0.13 + .005); // calculates the GST
    priceTax = (amount + GST); // calculate amount with tax

    printf("GST: %.2f\n", GST); // prints GST
    printf("Balance owing: $%.2f\n", priceTax); // print total amount

    //  calculations for change //

    cash = priceTax * 100 + 0.5;
    loonies = cash / 100;
    cash = cash % 100;
    balanceAmountLoonies = cash / 100.0;
    quarters = cash / 25;
    cash = cash % 25;
    balanceAmountQuarters = cash / 100.0;
    dimes = cash / 10;
    cash = cash % 10;
    balanceAmountDimes = cash / 100.0;
    nickels = cash / 5;
    cash = cash % 5;
    balanceAmountNikels = cash / 100.0;
    pennies = cash / 1;
    cash = cash % 1;
    balanceAmountPennies = cash / 100.0;

    printf("Loonies required: %d, balance owing $%.2f", loonies, balanceAmountLoonies);
    printf("\n");
    printf("Quarters required: %d, balance owing $%.2f", quarters, balanceAmountQuarters);
    printf("\n");
    printf("Dimes required: %d, balance owing $%.2f", dimes, balanceAmountDimes);
    printf("\n");
    printf("Nickels required: %d, balance owing $%.2f", nickels, balanceAmountNikels);
    printf("\n");
    printf("Pennies required: %d, balance owing $%.2f", pennies, balanceAmountPennies);
    printf("\n");
    return 0;
}