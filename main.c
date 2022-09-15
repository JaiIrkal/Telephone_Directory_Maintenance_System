#include <stdio.h>
#include <stdlib.h>
#include "FileFunctions.h"

#define USER_ID 1234

int main(int argc, char const *argv[])
{
    int inputUserId;
    int mainMenuChoice;
    print_main_heading();
    printf("                    Login Screen\n");
    printf("                    ============\n");

    printf("        Enter User ID   : ........");
    scanf("%d", &inputUserId);
    printf("%d", inputUserId);

    if (inputUserId == USER_ID)
    {

    main_menu:
        print_main_menu();
        printf("Enter your choice : ");
        scanf("%d", &mainMenuChoice);

        if (!(mainMenuChoice > 0 && mainMenuChoice <= 4))
        {
            printf("Enter a valid Option\n");
            goto main_menu;
        }
        else
        {
            if (mainMenuChoice == 1)
            {
            }
        }
    }
    else
    {
        printf("Incorrect User ID");
    }
    return 0;
}
