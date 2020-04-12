//==============================================
// Name:           Shabnoor Sayed
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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include<string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();/*
	printf("\n");*/
}

// getInt:
int getInt(void)
{
	int x1;
	char nl = 'x';
	while (nl != '\n')
	{
		scanf("%d%c", &x1, &nl);
		if (nl != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}

	}
	return x1;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int x1;
	x1 = getInt();
	while (x1<min || x1>max)
	{

		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		x1 = getInt();
	}
	return x1;
}

// yes:
int yes(void)
{
	int x1 = -1;
	char c1 = 'x', nl = 'x';
	scanf(" %c%c", &c1, &nl);
	while (!((nl == '\n') && ((c1 == 'Y') || (c1 == 'y') || (c1 == 'n') || (c1 == 'N'))))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &c1, &nl);
	}
	if ((c1 == 'y') || (c1 == 'Y'))
	{
		x1 = 1;
		printf("ok");
	}
	else if ((c1 == 'n') || (c1 == 'N')) {
		x1 = 0;
		printf("not ok");
	}
	return x1;
}

// menu:
int menu(void)
{
	int x1;
	printf("Contact Management System\n-------------------------\n1. Display contacts\n2. Add a contact\n3. Update a contact\n4. Delete a contact\n5. Search contacts by cell phone number\n6. Sort contacts by cell phone number\n0. Exit\n\nSelect an option:> ");
	x1 = getIntInRange(0, 6);
	return x1;
}

// contactManagerSystem:
void contactManagerSystem(void)
{
	static int cntrr = 0;
	struct Contact contactList[MAXCONTACTS] = { {
			{ "Rick", {'\0'}, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" } },
			{
			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" } },
			{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
			{
			{ "Sasha", {'\0'}, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" } },
	};
	int x, a = 1, y;
	while (a == 1)
	{
		x = menu();
		switch (x)
		{
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			y = yes();
			printf("\n");
			if (y == 1)
			{
				a = 0;
				printf("Contact Management System: terminated\n");
			}
			break;
		case 1:
			displayContacts(contactList, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 2:
			printf("\n");
			addContact(contactList, MAXCONTACTS);
			pause();
			if (cntrr == 0)
			{
				printf("\n");
			}
			cntrr++;
			printf("\n");
			break;
		case 3:
			updateContact(contactList, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 4:
			deleteContact(contactList, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 5:
			searchContacts(contactList, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		case 6:
			sortContacts(contactList, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		}
	}

}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
	int i, ninput = 1, check = 1;
	while (ninput == 1)
	{
		if (check == 1)
		{
			scanf("%10s", phoneNum);


		}
		else if (check == 2)
		{
			printf("Enter a 10-digit phone number: ");
			clearKeyboard();
			scanf("%10s", phoneNum);

		}


		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10)
		{
			ninput = 0;
			for (i = 0; i < 10; i++)
			{
				if ((int)phoneNum[i] < 48 || (int)phoneNum[i] > 57)
				{
					ninput = 1;
					check = 2;
					break;
				}
				else if (i == 10)
				{
					ninput = 0;
					check = 0;
					break;
				}
			}
		}
		else
			check = 2;

	}

}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, k = -1;
	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			k = i;
		}
	}
	return k;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");

}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	printf(" %s ", contact->name.firstName);
	if (strlen(contact->name.middleInitial) != 0)
	{
		printf("%s ", contact->name.middleInitial);
	}
	printf("%s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0)
	{
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int i, count = 0;
	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			displayContact(&(contacts[i]));
			count++;
		}
	}
	displayContactFooter(count);
	printf("\n");
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char icell[11], index;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(icell);
	index = findContactIndex(contacts, size, icell);
	if (index != -1)
	{
		printf("\n");
		displayContact(&contacts[findContactIndex(contacts, size, icell)]);
		printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	clearKeyboard();
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int i;
	i = findContactIndex(contacts, size, "");
	if (i != -1)
	{
		getContact(&contacts[i]);
		printf("--- New contact added! ---\n\n");

	}
	else
		printf("*** ERROR: The contact list is full! ***\n\n");

}

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	int index;
	static int count = 0;
	char phoneNum[11];
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	index = findContactIndex(contacts, size, phoneNum);

	if (index == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
		clearKeyboard();
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&(contacts[index]));
		printf("\n");
		/*if (count!=0)
			clearKeyboard();
		count++;*/
		clearKeyboard();
		printf("Do you want to update the name? (y or n): ");
		if (yes())
		{
			getName(&(contacts[index].name));
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes())
		{
			getAddress(&(contacts[index].address));
			if (count != 0)
			{
				clearKeyboard();
			}
		}

		count++;
		printf("Do you want to update the numbers? (y or n): ");
		if (yes())
		{
			getNumbers(&(contacts[index].numbers));

		}


		printf("--- Contact Updated! ---\n\n");

	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	int i;
	char phoneNum[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	i = findContactIndex(contacts, size, phoneNum);

	if (i == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&(contacts[i]));
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		clearKeyboard();

		if (yes())
		{
			strcpy(contacts[i].numbers.cell, "\0");
			printf("--- Contact deleted! ---\n");

			//	printf("\n");
		}
		printf("\n");
	}
}
void swapchar(char* first, char* second)
{
	char temp[20] = " ";
	strcpy(temp, first);
	strcpy(first, second);
	strcpy(second, temp);

}
void swapint(int* first, int* second)
{
	int temp = 0;
	temp = *first;
	*first = *second;
	*second = temp;

}
// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0)
			{
				swapchar(contacts[j].name.firstName, contacts[j + 1].name.firstName);
				swapchar(contacts[j].name.middleInitial, contacts[j + 1].name.middleInitial);
				swapchar(contacts[j].name.lastName, contacts[j + 1].name.lastName);
				swapint(&contacts[j].address.streetNumber, &contacts[j + 1].address.streetNumber);
				swapchar(contacts[j].address.street, contacts[j + 1].address.street);
				swapint(&contacts[j].address.apartmentNumber, &contacts[j + 1].address.apartmentNumber);
				swapchar(contacts[j].address.postalCode, contacts[j + 1].address.postalCode);
				swapchar(contacts[j].address.city, contacts[j + 1].address.city);
				swapchar(contacts[j].numbers.cell, contacts[j + 1].numbers.cell);
				swapchar(contacts[j].numbers.home, contacts[j + 1].numbers.home);
				swapchar(contacts[j].numbers.business, contacts[j + 1].numbers.business);
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n\n");
}