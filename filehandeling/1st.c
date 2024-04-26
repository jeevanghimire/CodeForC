#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    char c;
    char fileName[20];
    printf("Enter the name of file");
    scanf("%s", fileName);
    fptr = fopen(fileName, "w");
    if (fptr == NULL)
    {
        printf("File can not be created");
        exit(0);
    }
    printf("Enter Text. Hit enter key to stop writing");
    fflush(stdin);
    while ((c = getchar())!='\n')
        {
            fputc(c,fptr);
        }
    fclose(fptr);
    return 0;
}