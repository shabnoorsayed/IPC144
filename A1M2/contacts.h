//==============================================
// Name:           Full name here
// Student Number: #########
// Email:          userID@myseneca.ca
// Section:        XXX
// Date:           
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================

// Structure type Name declaration
struct Name 
{
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #1 here...
struct Address
{
	unsigned int streetNumber;
	char streetName[41];
	unsigned int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #1 here...

struct Numbers
{
	char cell[11],
		home[11],
		business[11];
};
