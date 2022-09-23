#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 50
#define FILENAME_SIZE 1024

int main()
{

    FILE *fp;
    char str[50];

    fp = fopen("amrit.txt", "r");
    bool keep_reading = true;

    if (fp == NULL)
    {
        printf("cannot open the file \n");
        exit(0);
    }
    else
    {
        while (fgets(str, sizeof(str), fp))
        {
            printf("%s", str);
        }

        fclose(fp);
    }

    printf(" last line =%s", str);
    printf("Size of last line is = %d\n", strlen(str));

    char substring[5];
    strncpy(substring, str, 4);
    substring[5] = '\0';

    printf("substring is = %s\n", substring);
    printf("Size of substring is = %d\n", strlen(substring));

    // converting string to integer
    int department_id = atoi(substring);

    department_id = department_id + 10;
    printf("department id is = %d\n", department_id);

    return 0;
}