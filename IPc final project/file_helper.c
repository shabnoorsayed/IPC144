/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)
   2)
   3)

   +--------------------------------------------------------+
   |                FILE: file_helper.c                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   |                                                        |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   |  !!!      DO NOT ALTER THE CONTENTS BELOW         !!!  |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS
#include "file_helper.h"

/********************************************************/
/* Read from the opened file the time (HH:MM) parts of  */
/* the record and return the time as decimal hours      */
/********************************************************/
double readTime(FILE* fp)
{
	int hour, min;

	fscanf(fp, "%d%*c", &hour);
	fscanf(fp, "%d", &min);

	return hour + (min / 60.0);
}

/********************************************************/
/* Read all the information on one rider from the valid */
/* (pre-opened) file and store it in the struct.        */
/* Return true when end of file has been reached.       */
/********************************************************/
int readFileRecord(FILE* fp, struct RiderInfo* info)
{
	int result = 1, ch;

	if (!feof(fp))
	{
		result = 0;
		
		// read from file and assign to data structure
		fscanf(fp, "%[^,]%*c", info->name);
		fscanf(fp, "%d", &info->age);
		fscanf(fp, " %c", &info->raceLength);
		info->startTime = readTime(fp);
		info->mountainTime = readTime(fp);
		info->finishTime = readTime(fp);
		
		// Last Field (withdrawn: may not be present)
		ch = fgetc(fp);
		info->withdrawn = 0;

		if (ch == ' ') 
		{
			ch = fgetc(fp);
			info->withdrawn = ch == 'W';
			ch = fgetc(fp);
		}
		
		// clear input file buffer until end of line (record):
		while (!feof(fp) && ch != '\n')
		{
			ch = fgetc(fp);
		}
	}

	return result;
}

void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}
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
int displayMenu(void) {
    int x1;
    printf("\n*********** Seneca Cycling Race Results*************\n");
    printf("What would you like to do?\n");
    printf("0 - Exit\n");
    printf("1 - Print top 3 riders in a category\n");
    printf("2 - Print all riders in a category\n");
    printf("3 - Print last 3 riders in a category\n");
    printf("4 - Print winners in all categories\n");

    x1 = getIntInRange(0, 4);
    return x1;
}