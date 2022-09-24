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
#include <conio.h>`

/* Declare constants and function prototypes */
#include "filefunctions.h"

/* Forward declaration of functions defined in DeptMaint.c */
int fnInitializeDeptCode();
int fnAddDept(char acDeptName[]);
void fnAddNewDepartment();
void fnPrintDepts();
/* Forward declaration of functions defined in EmpMaint.c */
int fnInitializeEmpCode();
void fnAddNewEmp();
void fnPrintEmp();
void fnAddTeleNum();
/* Forward declaration of functions defined in TeleEnq.c */
void fnEnqByTeleNum();
void fnEnqByName();

/*Function prototype*/
void fnMainMenu();

void fnTeleDirMenu();
void fnLoginValidate(char acUserId[]);

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

	printf("\n");
	printf("Telephone Directory Mainatinance System\n");
	printf("========================================");
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
	char choice;
	system("cls");
	fnGotoxy(25, 5);
	printf("Telephone Directory Maintainance System");
	fnGotoxy(25, 6);
	printf("========================================");
	fnGotoxy(25, 8);
	printf("Department Maintenance Menu");
	fnGotoxy(25, 9);
	printf("===========================");
	fnGotoxy(25, 11);
	printf("1. Add Departments");
	fnGotoxy(25, 12);
	printf("2. Print Department Details");
	fnGotoxy(25, 13);
	printf("3. Goto Main Menu");
	fnGotoxy(25, 15);
	printf("Enter your choice : ");

	choice = getch();

	switch (choice)
	{
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	default:
		printf("Enter a valid choice!!");
		fnDisplayDepartmentMenu();
	}
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
		break;
	case 2:
		fnPrintDepts();
		break;
	case 3:
		fnMainMenu();
		break;

	default:
		break;
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
	system("cls");
	fnGotoxy(25, 5);
	printf("Telephone Directory Maintainance System");
	fnGotoxy(25, 6);
	printf("=======================================");
	fnGotoxy(25, 8);
	printf("Main Menu");
	fnGotoxy(25, 9);
	printf("=========");
	fnGotoxy(25, 11);
	printf("1. Department Maintenance");
	fnGotoxy(25, 12);
	printf("2. Employee Maintenance");
	fnGotoxy(25, 13);
	printf("3. Telephone Directory Maintenance");
	fnGotoxy(25, 14);
	printf("4. Exit");
	fnGotoxy(25, 16);
	printf("Enter your choice : ");

	char choice = getch();

	switch (choice)
	{
	case '1':
		fnDepartmentMenu();
		break;
	case '2':
		fnEmpMenu();
		break;
	case '3':
		fnTeleDirMenu();
		break;
	case '4':
		exit(0);
		break;
	default:
		printf("Enter a valid choice");
		fnDisplayMainMenu();
	}
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
	system("cls");
	printf("Telephone Directory Maintainance System\n");
	printf("========================================");
	printf("Login Screen");
	printf("============\n");
	printf("Enter User ID 	:  ......");
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
