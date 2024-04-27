#include <stdio.h>

int main()
{
    int num;
    FILE *numFile = fopen("Num.txt", "r");
    FILE *primeFile = fopen("Prime.txt", "w");
    if (numFile == NULL || primeFile == NULL)
    {
        printf("File not found\n");
        return 0;
    }
    while (fscanf(numFile, "%d", &num) != EOF)
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
    fclose(numFile);
    fclose(primeFile);


return 0;
}