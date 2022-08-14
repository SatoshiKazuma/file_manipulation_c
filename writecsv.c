// C program for the above approach
#include <stdio.h>
#include <string.h>

// Driver Code
int main()
{

    FILE *fp = fopen("testfilee.csv", "a+");

    char name[50];
    long long int accountno, amount;

    if (!fp)
    {
        // Error in file opening
        printf("Can't open file\n");
        return 0;
    }

    // Asking user input for the
    // new record to be added
    printf("\nEnter Account Holder Name\n");
    scanf("%[^\n]s", name);
    printf("\nEnter Account Number\n");
    scanf("%lld", &accountno);
    printf("\nEnter Available Amount\n");
    scanf("%lld", &amount);

    // Saving data in file
    fprintf(fp, "%s, %lld, %lld\n", name,
            accountno, amount);

    printf("\nNew Account added to record");

    fclose(fp);
    return 0;
}