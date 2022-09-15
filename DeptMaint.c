#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

int main_menu()
{
    int choice;
    printf("1. Add Department\n");
    printf("2. Print Department Details\n");
    printf("3. Goto Main Menu\n");

    printf("\n");
    printf("Enter Your Choice:  ");
    scanf("%d", &choice);

    return choice;
}

void add_department()
{

    printf("department added testing....\n");
}

void print_department_details()
{

    printf("department details printed.\n");
}

int main()
{

    char department_name[SIZE];
    int choice;
    int department_code;

    printf("\n");
    printf("Telephone Directory Management System\n");
    printf("=======================================\n");
    printf("\n");
    printf("Department Maintenance Menu\n");

    while (1)
    {

        choice = main_menu();

        switch (choice)
        {

        case 1:
            add_department();
            break;

        case 2:
            print_department_details();
            break;

        case 3:
            main_menu();
            break;

        default:
            printf("Invalid Input !!!");
            exit(0);
        }
    }

    return 0;
}