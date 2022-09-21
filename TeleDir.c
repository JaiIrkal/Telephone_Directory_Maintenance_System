/******************************************************************************
 * Filename    : TelDir.c
 * Author      : E&R, Infosys Technologies Limited
 * Date        : 04-July-2005
 * Description : Displays the main menu for telephone directory maintenace and
 *				invokes the respective functions
 ******************************************************************************/

/* Include files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/* Declare constants and function prototypes */
//#include "filefunctions.h"

/* Forward declaration of functions defined in DeptMaint.c */
int fnInitializeDeptCode();
int fnAddDept(char acDeptName[]);
void fnAddNewDepartment();
void fnPrintDepts();
/* Forward declaration of functions defined in EmpMaint.c */
int fnInitializeEmpCode();
void fnAddNewEmp();
void fnPrintEmp();

/* Forward declaration of functions defined in TeleEnq.c */
void fnEnqByTeleNum();
void fnEnqByName();

/*Function prototype*/
void fnAddTeleNum();
void fnMainMenu();
void fnTeleDirMenu();
void fnLoginValidate(char acUserId[]);

void fnLoginScreen();

/******************************************************************************
 * Function: fnDisplayTeleDirMenu
 * Description: Displays the Telephone Directory Maintenance menu. Waits for user's
 *		input in keyboard using scanf. Returns control back to calling function
 *		only after user has typed a choice.
 * Input Parameters: None
 * Returns: The user's choice.
 *******************************************************************************/

int fnDisplayTeleDirMenu()
{
	printf("Telephone Directory Maintenance System\n");
	printf("======================================\n");
	printf("Telephone Directory Maintenance Menu\n");
	printf("====================================\n");
	printf("1. Add Telephone Number\n");
	printf("2. Goto Main Menu\n");

	printf("Enter your choice : \n");
	char choice = getch();

	if (choice == '1')
		return 1;
	if (choice == '2')
		return 2;
}

/******************************************************************************
 * Function: fnDisplayTeleEnqMenu
 * Description: Displays the Telephone Enquiry menu. Waits for user's
 *		input in keyboard using scanf. Returns control back to calling function
 *		only after user has typed a choice.
 * Input Parameters: None
 * Returns: The user's choice.
 ******************************************************************************/

int fnDisplayTeleEnqMenu()
{
	printf("Telephone Directory Maintenance System\n");
	printf("%s", "======================================\n");
	printf("Telephone Enquiry Menu\n");
	printf("======================\n");

	printf("1. Enquiry on Employee Name\n");
	printf("2. Enquiry on Employee Number\n");
	printf("3. Goto Main Menu\n");

	printf("Enter your choice : \n");
	char choice = getch();

	if (choice == '1')
		return 1;
	if (choice == '2')
		return 2;
	if (choice == '3')
		return 3;
}

/******************************************************************************
 * Function: fnTeleEnqMenu
 * Description: Handles the Telephone Enquiry menu. Calls fnDisplayTeleEnqMenu
 *		function to display the menu. Choice of user is handled by this
 *		function.
 * Input Parameters: None
 * Returns: None
 ******************************************************************************/
void fnTeleEnqMenu()
{
	int choice = fnDisplayTeleEnqMenu();

	switch (choice)
	{
	case 1:
		fnEnqByName();
		break;
	case 2:
		fnEnqByTeleNum();
		break;
	case 3:
		fnMainMenu();
		break;
	default:
		printf("Enter valid option\n");
	}
}

/******************************************************************************
* Function: fnTeleDirMenu
* Description: Handles the Telephone Directory Maintenance menu. Calls
	fnDisplayTeleDirMenu function to display the menu. Choice of user is
	handled by this	function.
* Input Parameters: None
* Returns: None
******************************************************************************/

void fnTeleDirMenu()
{
	int choice = fnDisplayTeleDirMenu();

	switch (choice)
	{
	case 1:
		fnAddTeleNum();
	case 2:
		fnMainMenu();
	}
}

/******************************************************************************
 * Function: fnDisplayEmpMenu
 * Description: Displays the Employee Maintenance menu. Waits for user's
 *		input in keyboard using scanf. Returns control back to calling function
 *		only after user has typed a choice.
 * Input Parameters: None
 * Returns: The user's choice.
 ******************************************************************************/

int fnDisplayEmpMenu()
{
	printf("Telephone Directory Maintenace System\n");
	printf("================================\n");

	printf("1. Add Employee\n");
	printf("2. Print Employee Details\n");
	printf("3. Goto Main Menu\n");

	printf("Enter your Choice: \n");

	char choice = getch();

	if (choice == '1')
		return 1;
	if (choice == '2')
		return 2;
	if (choice == '3')
		return 3;
}

/******************************************************************************
 * Function: fnDisplayDepartmentMenu
 * Description: Displays the Department Maintenance menu. Waits for user's
 *		input in keyboard using scanf. Returns control back to calling function
 *		only after user has typed a choice.
 * Input Parameters: None
 * Returns: The user's choice.
 ******************************************************************************/

int fnDisplayDepartmentMenu()
{
	printf("Telephone Directory Maintenance System\n");
	printf("======================================\n");
	printf("\n");
	printf("Add a Department\n");
	printf("=================\n");
	printf("\n");
	printf("1. Add Department\n");
	printf("2. Print Department Details\n");
	printf("3. Goto Main Menu\n");
	printf("\n");
	printf("Enter your Choice :");
	char choice = getch();
	if (choice == '1')
		return 1;
	if (choice == '2')
		return 2;
	if (choice == '3')
		return 3;
}

/******************************************************************************
 * Function: fnEmpMenu
 * Description: Handles the Employee Maintenance menu. Calls fnDisplayEmpMenu
 *		function to display the menu. Choice of user is handled by this
 *		function.
 * Input Parameters: None
 * Returns: None
 ******************************************************************************/

void fnEmpMenu()
{
	int choice = fnDisplayEmpMenu();

	switch (choice)
	{
	case 1:
		fnAddNewEmp();
	case 2:
		fnPrintEmp();
	case 3:
		fnMainMenu();
	default:
		printf("Enter a valid option\n");
	}
}

/******************************************************************************
 * Function: fnDepartmentMenu
 * Description: Handles the Department menu. Calls fnDisplayDepartmentMenu
 *		function to display the menu. Choice of user is handled by this
 *		function.
 * Input Parameters: None
 * Returns: None
 ******************************************************************************/

void fnDepartmentMenu()
{
	int choice = fnDisplayDepartmentMenu();
	switch (choice)
	{
	case 1:
		fnAddNewDepartment();
	case 2:
		fnPrintDepts();
	case 3:
		fnMainMenu();
	}
}

/******************************************************************************
 * Function: fnDisplayMainMenu
 * Description: Displays the main menu of telephone directory system. Then
 *		waits for user's input using scanf function. Until the user types in
 *		a selection, control will not be returned to the calling function.
 * Input Parameters: None
 * Returns: The user's choice
 ******************************************************************************/

int fnDisplayMainMenu()
{

	printf("Telephone Directory Maintenance System\n");
	printf("======================================\n");
	printf("Main Menu\n");
	printf("=========\n");
	printf("1. Department Maintenance\n");
	printf("2. Employee Maintenance\n");
	printf("3. Telephone Directory Maintenance\n");
	printf("4. Exit\n");

	printf("Enter your choice : \n");
	char choice = getch();

	if (choice == '1')
		return 1;
	if (choice == '2')
		return 2;
	if (choice == '3')
		return 3;
	if (choice == '4')
		exit(0);
}

/******************************************************************************
 * Function: fnMainMenu
 * Description: Calls fnDisplayMainMenu and waits for user's choice. Upon
 *     user's selection, does appropriate action. If user chooses 'exit'
 *     option, returns control back to the calling function.
 * Input Parameters: None
 * Returns : None
 ******************************************************************************/

void fnMainMenu()
{
	int choice = fnDisplayMainMenu();
	switch (choice)
	{
	case 1:
		fnDepartmentMenu();
		break;
	case 2:
		fnEmpMenu();
		break;
	case 3:
		fnTeleDirMenu();
		break;
	case 4:
		exit(0);
	default:
		printf(" Enter a valid option");
		fnMainMenu();
	}
}

/******************************************************************************
* Function: fnLogin
Description: Check for valid User Id and calls fnMainMenu.
If invalid employee id is entered for User Id, error message "Login Denied"
is displayed and quits the application.
* Input Parameters: None
* Return : None
******************************************************************************/

void fnLogin()
{
	fnLoginScreen();
}
void fnLoginScreen()
{
	char chUserID[10];
	printf("\n");
	printf("			Telephone Directory Maintainance System\n");
	printf("			========================================\n");
	printf("				Login Screen\n");
	printf("				============			 \n");
	printf("\n");
	printf("     Enter User ID 	:  ......");
	// scanf("%s", chUserID);
	getch();
	fnMainMenu();
}
void fnLoginValidate(char acUserId[])
{
}

/******************************************************************************
 * Function: main
 * Description: Entry point of program.
 * Input Parameters: None
 ******************************************************************************/

int main(int argc, char **argv)
{
	/* calling fnLogin function to generate login screen*/
	fnLogin();

	/* Return a success code to Operating System */
	return 0;
}

/******************************************************************************
 * End of TelDir.c
 ******************************************************************************/
