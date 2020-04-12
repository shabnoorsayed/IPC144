//==============================================
// Name:           Shabnoor Sayed
// Student Number: 133649194
// Email:          ssayed10@myseneca.ca
// Section:        NOO
// Workshop:       5 (at-home)
//==============================================

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 4		

struct Employee{
	int id;
	int age;
	double salary;
};

int main(void){

	int choice = 0, i, valid_emp = 0, ID, flag, num;
	struct Employee emp[SIZE] = { {0} };
	printf("---=== EMPLOYEE DATA ===---\n\n");
	do{

		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");

		printf("Please select from the above options: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice){
		case 0:
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;

		case 1:
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++){

				if (emp[i].id > 0){
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			}
			printf("\n");
			break;
		case 2:
			printf("Adding Employee\n");
			printf("===============\n");

			if (valid_emp >= SIZE){

				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			else{

				for (i = SIZE; i >= 0; i--){

					if (emp[i].id == 0)
						num = i;
				}
				printf("Enter Employee ID: ");
				scanf("%d", &emp[num].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[num].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[num].salary);
				printf("\n");
				valid_emp++;
			}
			break;
		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");
			flag = 0;

			do{

				printf("Enter Employee ID: ");
				scanf("%d", &ID);
				for (i = 0; i < valid_emp; i++){

					if (ID == emp[i].id){

						flag = 1;
						num = i;
					}
				}
				if (flag == 0){

					printf("*** ERROR: Employee ID not found! ***\n");
				}
			} while (flag == 0);
			if (flag == 1){

				printf("The current salary is %.2lf\n", emp[num].salary);
				printf("Enter Employee New Salary: ");
				scanf("%lf", &emp[num].salary);
				printf("\n");
			}
			break;
		case 4:
			printf("Remove Employee\n");
			printf("===============\n");
			flag = 0;
			do{
				printf("Enter Employee ID: ");
				scanf("%d", &ID);
				for (i = 0; i < valid_emp; i++){
					if (ID == emp[i].id){
						flag = 1;
						num = i;
					}
				}
				if (flag == 0){
					printf("*** ERROR: Employee ID not found! ***\n");
				}
			} while (flag == 0);
			if (flag == 1){
				printf("Employee %d will be removed\n", ID);
				emp[num].id = 0;
				valid_emp--;
			}
			printf("\n");
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (choice != 0);

	return 0;
}


// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 222
Enter Employee Age: 22
Enter Employee Salary: 22222.22

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 333
Enter Employee Age: 33
Enter Employee Salary: 33333.33

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 444
Enter Employee Age: 44
Enter Employee Salary: 44444.44

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 555
Enter Employee Age: 55
Enter Employee Salary: 55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   33333.33
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 123
*** ERROR: Employee ID not found! ***
Enter Employee ID: 321
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
The current salary is 33333.33
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
333       33   99999.99
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 789
*** ERROR: Employee ID not found! ***
Enter Employee ID: 987
*** ERROR: Employee ID not found! ***
Enter Employee ID: 333
Employee 333 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 666
Enter Employee Age: 66
Enter Employee Salary: 66666.66

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
222       22   22222.22
666       66   66666.66
444       44   44444.44
555       55   55555.55

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
