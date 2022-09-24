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
#include <string.h>

#include "Filefunctions.h"
/* Stores the Code of the next department that may be added */
int giDeptCode;

int iFlag;
int iFlag2;

void generateDeptCode();

/******************************************************************************
 * Function: fnInitializeDeptCode
 * Description: Reads all the departments in the department file and initializes
 *		the global variable giDeptCode for any new department to be added to
 *		the system. The Dept file should've been opened in the program already!
 * Input Parameters: None
 ******************************************************************************/

void fnInitializeDeptCode()
{
    char deptDetails[20];
    // char dept_name[4];

    fnOpenFile(DEP_FILE);
    while (fnReadFile(deptDetails, DEP_FILE, CURRENT) == 0)
    {
        sscanf(deptDetails, "%d%*s", &giDeptCode);
    }
    printf("DEPT_CODE: %d \n", giDeptCode);

    fnCloseFile(DEP_FILE);
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
    int i;
    char acLine[20];

    fnOpenFile(DEP_FILE);

    sprintf(acLine, "%4d %14s", giDeptCode, acDeptName);
    fnWriteFile(acLine, DEP_FILE);
    fnCloseFile(DEP_FILE);

    fnDepartmentMenu();
}

/******************************************************************************
 * Function: fnPrintDepts
 * Description: Prints all the department codes and names that exist in the
 *		file dept.txt
 * Input Parameters: None
 ******************************************************************************/

void fnPrintDepts()
{
    char deptDetails[20];
    fnOpenFile(1);
    system("cls");
    printf("Telephone Directory Maintenance System\n");
    printf("======================================\n");
    printf("Department Details\n");
    printf("==================\n");

    while (fnReadFile(deptDetails, DEP_FILE, CURRENT) == 0)
        printf("%s\n", deptDetails);

    printf("Enter any key to continue.....\n");
    getch();

    fnDepartmentMenu();
}

/******************************************************************************
 * Function: fnAddNewDepartment
 * Description: Allows user to visually add a new department into the system
 * Input Parameters: None
 ******************************************************************************/

void fnAddNewDepartment()
{
    fnInitializeDeptCode();
    char dept_name[20];
    system("cls");
    printf("Telephone Directory Maintenance System");
    printf("\n======================================");
    printf("\nAdd a Department");
    printf("\nEnter Department Name :  .........");
    printf("\nDepartment Code  :    ");
    generateDeptCode();
    printf("%d\n", giDeptCode);
    printf("\nPress any key to continue");
    fnGotoxy(25, 3);
    scanf("%s", dept_name);
    fnAddDept(dept_name);
    getch();
    fnDepartmentMenu();
}

/******************************************************************************
 * End of DeptMaint.c
 ******************************************************************************/

void generateDeptCode()
{
    giDeptCode++;
}
