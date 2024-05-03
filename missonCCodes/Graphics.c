#include <stdio.h>
int main()
{
    FILE *numbFile= fopen("numb.txt","r+");
    FILE *primeFile = fopen("Prime.txt","w");
    int numb;
    printf("Enter the number you want :\n");
    scanf("%d",&numb);
    int NUmbers[numb];
    for (int i = 0; i < numb; i++)
    {
        scanf("%d ",&NUmbers[i]);
        fprintf(numbFile,"%d\t",NUmbers[i]);
    }
    int num=0;
    while (fscanf(numbFile, "%d", &num) != EOF)
    {
        
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                break;
            }
            if (i == num - 1) {
                fprintf(primeFile, "%d\t", num);
            }
        }
    }
    fclose(numbFile);
    fclose(primeFile);
    
return 0;
}