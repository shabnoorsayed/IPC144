//==============================================
// Name:           Shabnoor Sayed	
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:			NOO
// Date:           
//==============================================
// Assignment:     1
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"

int main(void)

{
	// Declare variables here:

	struct Contacts contact;

	// Display  title

	printf("Contact Management System\n");

	printf("=========================\n");

	// Call the Contact function getName to store the values for the Name member

	getName(&contact.name);

	// Call the Contact function getAddress to store the values for the Address member

	getAddress(&contact.address);

	// Call the Contact function getNumbers to store the values for the Numbers member

	getNumbers(&contact.numbers);


	// Display Contact summary details

	printf("\n");

	printf("Contact Details\n");

	printf("===============\n");

	printf("Name Details\n------------\n");

	printf("First name: %s\nMiddle initial(s): %s\nLast name: %s\n\n", contact.name.firstName, contact.name.middleInitial, contact.name.lastName);

	printf("Address Details\n---------------\n");

	printf("Street number: %d\nStreet name: %s\nApartment: %d\nPostal code: %s\nCity: %s\n\n", contact.address.streetNumber, contact.address.street, contact.address.apartmentNumber, contact.address.postalCode, contact.address.city);

	printf("Phone Numbers\n-------------\n");

	printf("Cell phone number: %s\nHome phone number: %s\nBusiness phone number: %s\n\n", contact.numbers.cell, contact.numbers.home, contact.numbers.business);


	// Display Completion Message
	printf("Structure test for Contact using functions done!\n");

	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
=========================
Please enter the contact's first name: Wilma Dee
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): N. O.
Please enter the contact's last name: Flint Rubble
Please enter the contact's street number: 30
Please enter the contact's street name: Bedrock St.
Do you want to enter an apartment number? (y or n): y
Please enter the contact's apartment number: 12
Please enter the contact's postal code: Z8Z 7R7
Please enter the contact's city: North York
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 9992223333
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 8881112222
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 3337779999

Contact Details
===============
Name Details
------------
First name: Wilma Dee
Middle initial(s): N. O.
Last name: Flint Rubble

Address Details
---------------
Street number: 30
Street name: Bedrock St.
Apartment: 12
Postal code: Z8Z 7R7
City: North York

Phone Numbers
-------------
Cell phone number: 9992223333
Home phone number: 8881112222
Business phone number: 3337779999

Structure test for Contact using functions done!
*/