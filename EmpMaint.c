/******************************************************************************
 * Filename    : EmpMaint.c
 * Author      : Education & Research Dept, Infosys Technologies Limited
 * Date        : 11-Mar-2009
 * Description : Contains the functions required for the employee
 *		maintenance.
 *******************************************************************************/
/* Included the libraries here */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "filefunctions.h"

/* Stores the Code of the next employee that may be added */

int giEmpCode;

/******************************************************************************
 * Function: fnInitializeEmpCode
 * Description: Reads all the employees in the employee file and initializes
 *		the global variable giEmpCode for any new employee to be added to
 *		the system. The emp file should've been opened in the program already!
 * Input Parameters: None
 ******************************************************************************/

int fnInitializeEmpCode()
{
    char chEmpDetails[20];

    // We open the emp.txt file
    fnOpenFile(EMP_FILE);

    while (fnReadFile(chEmpDetails, EMP_FILE, CURRENT) == 0)
    {

        sscanf(chEmpDetails, "%d%*s", &giEmpCode);
    }

    printf("EMP_CODE: %d", giEmpCode);

    fnCloseFile(EMP_FILE);
}

/******************************************************************************
 * Function: fnAddEmp
 * Description: Adds a new employee entry into the Emp file
 *		The Emp file should've been opened in the program already!
 * Input Parameters: None
 * Returns: Zero on success. 1 if dept name exists already.
 ******************************************************************************/
void fnAddNewEmp()
{
}

/******************************************************************************
 * Function: fnPrintEmps
 * Description: Prints all the employee codes and names that exist in the
 *		file emp.txt
 * Input Parameters: None
 ******************************************************************************/
void fnPrintEmp()
{
    fnOpenFile(EMP_FILE);
}