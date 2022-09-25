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

#include "filefunctions.h"

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
    system("cls");

    fnGotoxy(25, 5);
    printf("Telephone Directory Maintenance System");
    fnGotoxy(25, 6);
    printf("======================================");
    fnGotoxy(30, 8);
    printf("Display all the Departments");
    fnGotoxy(30, 9);
    printf("===========================");

    fnGotoxy(25, 11);
    printf("Department Code");
    fnGotoxy(50, 11);
    printf("Department Name");
    char deptDetails[20];
    char dept_name[15];
    int dept_id;
    fnOpenFile(DEP_FILE);
    int i = 0;
    while (fnReadFile(deptDetails, DEP_FILE, CURRENT) == 0)
    {
        sscanf(deptDetails, "%d%s", &dept_id, &dept_name);
        fnGotoxy(30, 12 + i);
        printf("%d", dept_id);
        fnGotoxy(56, 12 + i);
        printf("%s", dept_name);

        i++;
    }
    fnGotoxy(25, 13 + i);
    printf("Enter any key to continue :");
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
