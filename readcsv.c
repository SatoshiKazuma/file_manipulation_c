#include <stdio.h>
typedef struct
{
    char user[50];
    long long acc_nmbr;
    long long acc_blnc;
} Account;

int main()
{
    FILE *file = fopen("testfilee.csv", "r");

    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    Account account[100];

    int read = 0;
    int records = 0;
    do
    {
        read = fscanf(file,"%49[^,],%lld,%lld", account[records].user, &account[records].acc_nmbr, &account[records].acc_blnc);
        if (read == 3)
            records++;
        if (read != 3 && !feof(file))
        {
            printf("File formar error\n");
            return 1;
        }
        if (ferror(file))
        {
            printf("Error reading file.\n");
            return 1;
        }
    } while (!feof(file));
    fclose(file);
    //printing the contents
    printf("%d records read\n\n\n",records);
    for (int i = 0; i < records; i++)
    {
        printf("%s %lld %lld",
                account[i].user,
                account[i].acc_nmbr,
                account[i].acc_blnc);
        printf("\n");
    }
    return 0;
}
