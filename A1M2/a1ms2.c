//==============================================
// Name:           Shabnoor Sayed
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Date:           9-March-2020
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


#include <string.h>
#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Name fullName = { { 0 } };
	struct Address contactAddress;
	struct Numbers phoneInfo = { { 0 } };
	char alternate;


	printf("Contact Management System\n");                                          // Display title
	printf("-------------------------\n");

	// Contact name input

	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]%*c", fullName.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c%*c", &alternate);

	if ((alternate == 'y') || (alternate == 'Y'))

	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]%*c", fullName.middleInitial);
	}

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]%*c", fullName.lastName);


	// Contact address input:

	printf("Please enter the contact's street number: ");
	scanf("%d%*c", &contactAddress.streetNumber);

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]%*c", contactAddress.streetName);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c%*c", &alternate);

	if ((alternate == 'y') || (alternate == 'Y'))

	{
		printf("Please enter the contact's apartment number: ");
		scanf("%d%*c", &contactAddress.apartmentNumber);
	}

	printf("Please enter the contact's postal code: ");



	scanf(" %7[^\n]%*c", contactAddress.postalCode);

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]%*c", contactAddress.city);


	// Contact Numbers Input:

	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c%*c", &alternate);

	if ((alternate == 'y') || (alternate == 'Y'))

	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%20[^\n]%*c", phoneInfo.cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");


	scanf(" %c%*c", &alternate);

	if ((alternate == 'y') || (alternate == 'Y'))

	{
		printf("Please enter the contact's home phone number: ");
		scanf("%20[^\n]%*c", phoneInfo.home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c%*c", &alternate);


	if ((alternate == 'y') || (alternate == 'Y'))

	{
		printf("Please enter the contact's business phone number: ");
		scanf("%20[^\n]%*c", phoneInfo.business);
	}

	// Display Contact Summary Details

	printf("\nContact Details");
	printf("\n---------------");

	printf("\nName Details:");
	printf("\nFirst name: %s", fullName.firstName);
	printf("\nMiddle initial(s): %s", fullName.middleInitial);

	printf("\nLast name: %s", fullName.lastName);
	printf("\n");

	printf("\nAddress Details:");
	printf("\nStreet number: %d", contactAddress.streetNumber);
	printf("\nStreet name: %s", contactAddress.streetName);

	printf("\nApartment: %d", contactAddress.apartmentNumber);
	printf("\nPostal code: %s", contactAddress.postalCode);
	printf("\nCity: %s", contactAddress.city);
	printf("\n");

	printf("\nPhone Numbers:");
	printf("\nCell phone number: %s", phoneInfo.cell);
	printf("\nHome phone number: %s", phoneInfo.home);
	printf("\nBusiness phone number: %s", phoneInfo.business);

	// Display Completion Message

	printf("\n\nStructure test for Name, Address, and Numbers Done!\n");

	return 0;
}

/*  SAMPLE OUTPUT:
    
    Contact Management System
    -------------------------
    Please enter the contact's first name: Tom
    Do you want to enter a middle initial(s)? (y or n): y
    Please enter the contact's middle initial(s): L. A.
    Please enter the contact's last name: Wong Song
    Please enter the contact's street number: 20ex
    Please enter the contact's street name: Keele Street
    Do you want to enter an apartment number? (y or n): y
    Please enter the contact's apartment number: 40
    Please enter the contact's postal code: A8A 4J4
    Please enter the contact's city: North York
    Do you want to enter a cell phone number? (y or n): Y
    Please enter the contact's cell phone number: 9051116666
    Do you want to enter a home phone number? (y or n): Y
    Please enter the contact's home phone number: 7052227777
    Do you want to enter a business phone number? (y or n): Y
    Please enter the contact's business phone number: 4163338888

    Contact Details
    ---------------
    Name Details:
    First name: Tom
    Middle initial(s): L. A.
    Last name: Wong Song

    Address Details:
    Street number: 20
    Street name: Keele Street
    Apartment: 40
    Postal code: A8A 4J4
    City: North York

    Phone Numbers:
    Cell phone number: 9051116666
    Home phone number: 7052227777
    Business phone number: 4163338888

    Structure test for Name, Address, and Numbers Done!
*/