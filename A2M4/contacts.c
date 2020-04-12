//==============================================
// Name:           Shbanoor Sayed
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Date:           09-04-2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string.h>
// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include"contactHelpers.h"
#include"contacts.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name)
{
	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]", name->firstName);
	//while (getchar() != '\n' && getchar() != EOF);
	clearKeyboard();
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	//while (getchar() != '\n' && getchar() != EOF);

	if (yes())
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]", name->middleInitial);
		//while (getchar() != '\n' && getchar() != EOF);
		clearKeyboard();
	}
	else
		strcpy(name->middleInitial, "");
	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]", name->lastName);
	//while (getchar() != '\n' && getchar() != EOF);
	clearKeyboard();
}
// getAddress:
void getAddress(struct Address* address)
{
	int x, y = 0, i;
	char c;
	printf("Please enter the contact's street number: ");
	while (y == 0)
	{
		address->streetNumber = getInt();
		if (address->streetNumber < 0)
		{
			printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		}
		else
		{
			y = 1;
		}
	}

	printf("Please enter the contact's street name: ");
	scanf("%[^\n]s", address->street);
	clearKeyboard();
	printf("Do you want to enter an apartment number? (y or n): ");
	x = yes();
	if (x == 1)
	{
		y = 0;
		printf("Please enter the contact's apartment number: ");
		while (y == 0)
		{
			address->apartmentNumber = getInt();
			if (address->apartmentNumber < 0)
			{
				printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			}
			else
			{
				y = 1;
			}
		}
	}
	printf("Please enter the contact's postal code: ");
	for (i = 0; i < 7; i++)
	{
		c = getchar();

		if (i == 7)
		{
			break;
		}
		else if (c == '\n')
		{
			break;
		}
		else
		{
			address->postalCode[i] = c;
		}
	}
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf("%[^\n]s", address->city);
	clearKeyboard();
}


// getNumbers:
void getNumbers(struct Numbers* numbers)
{

	int x;
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	clearKeyboard();
	printf("Do you want to enter a home phone number? (y or n): ");
	x = yes();
	if (x == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
		clearKeyboard();
	}
	else
		strcpy(numbers->home, "");

	printf("Do you want to enter a business phone number? (y or n): ");
	x = yes();
	if (x == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
	else
		strcpy(numbers->business, "");
}


// getContact:
void getContact(struct Contact* contact)
{
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}