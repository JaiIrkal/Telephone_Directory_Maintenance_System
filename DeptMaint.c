/******************************************************************************
 * Filename    : DeptMaint.c
 * Author      : Education & Research Dept, Infosys Technologies Limited
 * Date        : 11-Mar-2009
 * Description : Contains the functions required for the department
 *		maintenance.
 *******************************************************************************/

/* Include files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//#include "filefunctions.h"
/* Stores the Code of the next department that may be added */
int giDeptCode;

int iFlag;
int iFlag2;

/******************************************************************************
 * Function: fnInitializeDeptCode
 * Description: Reads all the departments in the department file and initializes
 *		the global variable giDeptCode for any new department to be added to
 *		the system. The Dept file should've been opened in the program already!
 * Input Parameters: None
 ******************************************************************************/

void fnInitializeDeptCode()
{
<<<<<<< HEAD
    printf("Init dept");
=======
    
>>>>>>> 03d37295f2cbf0000d5b39f6ba4a821147ab3f00
}

/******************************************************************************
 * Function: fnAddDept
 * Description: Adds a new department entry into the Dept file
 *		The Dept file should've been opened in the program already!
 * Input Parameters: None
 * 	char acDeptName[] - Name of the new dept
 * Returns: Zero on success. 1 if dept name exists already.
 ******************************************************************************/

int fnAddDept(char acDeptName[])
{
    
}

/******************************************************************************
 * Function: fnPrintDepts
 * Description: Prints all the department codes and names that exist in the
 *		file dept.txt
 * Input Parameters: None
 ******************************************************************************/

void fnPrintDepts()
{
    // fnOpenFile(1);

    printf("Department Details");

    printf("Enter any key to continue.....\n");
    getch();

    // fnDepartmentMenu();
}

/******************************************************************************
 * Function: fnAddNewDepartment
 * Description: Allows user to visually add a new department into the system
 * Input Parameters: None
 ******************************************************************************/

void fnAddNewDepartment()
{
    char dept_name[20];
    system("cls");
    printf("Telephone Directory Maintenance System");
    printf("\n======================================");
    printf("\nAdd a Department");
    printf("\nEnter Department Name :");
    // scanf("%s", dept_name);
    printf("\nDepartment Code  :");
    // generateDeptCode();
    // printf("%d", giDeptCode);
    printf("\nPress any key to continue");
    // fnAddDept(dept_name);
    getch();
    // fnDepartmentMenu();
}

/******************************************************************************
 * End of DeptMaint.c
 ******************************************************************************/

void generateDeptCode()
{
    giDeptCode++;
}
