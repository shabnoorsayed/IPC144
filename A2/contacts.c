//==============================================
// Name:           Shabnoor Sayed
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Date:           26/03/2020
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:
#include "contactHelpers.h"



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )

// getName:
///////////////////////////////////////////////////////////////////////////////////
void getName(struct Name* name)
{
	//char option[2] = ("n");
	int opt;

	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]%*c", name->firstName);


	printf("Do you want to enter a middle initial(s)? (y or n): ");
	opt = yes();
	//scanf("\n%c", option);

	//if ((*option == 'n') || (*option == 'N')) {
	if (opt == 0)
	{
		name->middleInitial[0] = '\0';
	}
	else
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]%*c", name->middleInitial);
	}
	clearKeyboard();

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]%*c", name->lastName);

}
///////////////////////////////////////////////////////////////////////////////////


// getAddress:
///////////////////////////////////////////////////////////////////////////////////
void getAddress(struct Address* address)
{
	//char option[2] = ("n");

	printf("Please enter the contact's street number: ");
	do
	{
		address->streetNumber = getInt();
		if (address->streetNumber < 1)
		{
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");

		}
	} while (address->streetNumber < 1);
	//scanf("%d", &address->streetNumber);

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]%*c", address->street);   //using this way to avoid the problem of missing 'space' in names like "Keele Street"  
	//scanf(" %40s[^\n]", address->street); 



	printf("Do you want to enter an apartment number? (y or n): ");
	int opt = yes();
	//scanf("\n%c", option);

	//if ((*option == 'n') || (*option == 'N')) {
	if (opt == 0)
	{
		address->apartmentNumber = 0;
	}
	else
	{
		printf("Please enter the contact's apartment number: ");
		do
		{
			address->apartmentNumber = getInt();
			if (address->apartmentNumber < 1)
			{
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			}
		} while (address->apartmentNumber < 1);

		//scanf("%d", &address->apartmentNumber);
	}
	//clearKeyboard();

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]%*c", address->postalCode);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]%*c", address->city);
}
///////////////////////////////////////////////////////////////////////////////////


// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
///////////////////////////////////////////////////////////////////////////////////
void getNumbers(struct Numbers* numbers)
{
	//char option[2] = ("n");
	int optYesNo;

	//CELL
	/*printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("\n%c", option);
	if ((*option == 'n') || (*option == 'N')) {
		numbers->cell[0] = '\0';
	}
	else {*/
	printf("Please enter the contact's cell phone number: ");
	scanf(" %20[^\n]%*c", numbers->cell);
	//}

	//HOME
	printf("Do you want to enter a home phone number? (y or n): ");
	optYesNo = yes();
	//scanf("\n%c", option);

	//if ((*option == 'n') || (*option == 'N')) {
	if (optYesNo == 0)
	{
		numbers->home[0] = '\0';
	}
	else
	{
		printf("Please enter the contact's home phone number: ");
		scanf(" %20[^\n]%*c", numbers->home);
	}

	//BUSINESS
	printf("Do you want to enter a business phone number? (y or n): ");
	optYesNo = yes();
	//scanf("\n%c", option);

	//if ((*option == 'n') || (*option == 'N')) {
	if (optYesNo == 0)
	{
		numbers->business[0] = '\0';
	}
	else
	{

		printf("Please enter the contact's business phone number: ");
		scanf(" %20[^\n]%*c", numbers->business);
	}
	//printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+

// getContact
///////////////////////////////////////////////////////////////////////////////////
void getContact(struct Contact* contact)
{
	struct Contact locContact;

	getName(&locContact.name);
	getAddress(&locContact.address);
	getNumbers(&locContact.numbers);

	*contact = locContact;
	// Use an open and close curly brace with a blank line
}
