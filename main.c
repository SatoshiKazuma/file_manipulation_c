// file manipulation
//  I will cover the basics of opening reading writing and closing files in this project
#include <stdio.h>
#include <string.h>
int main()
{
    char teststring[30];
    FILE *filePointer;
    char name[10];
    printf("Enter username: ");
    scanf("%s", name);
    if (!strcmp(name,"oreneus"))
    {
        filePointer = fopen("testfile.txt", "r");
        fgets(teststring, 30, filePointer);
        printf("%s \n", teststring);
        fclose(filePointer);
    }
}