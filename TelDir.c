#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char inputUserId[20];
    printf("\n");
    printf("        Telephone Directory Maintenance System\n");
    printf("        ======================================\n");
    printf("                    Login Screen\n");
    printf("                    ============\n");
    printf("\n");
    printf("        Enter User ID   : ........");
    scanf("%s", inputUserId);
    printf("%s", inputUserId);

    return 0;
}
