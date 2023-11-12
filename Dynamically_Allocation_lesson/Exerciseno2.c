#include <stdio.h>
#include <stdlib.h>

int length(char *array)
{
    int i;
    for (i = 0; array[i] != '\0'; i++)
        ;
    return i;
}

char *join(char *arr1, char *arr2)
{
    int n1 = length(arr1);
    int n2 = length(arr2);
    int i, j;

    char *newstr = (char *)malloc((n1 + n2 + 1) * sizeof(char));
    if (newstr == NULL)
    {
        printf("Allocation Failed:\n");
        exit(2);
    }

    for (i = 0; i < n1; i++)
    {
        newstr[i] = arr1[i];
    }

    for (j = 0; j < n2; j++, i++)
    {
        newstr[i] = arr2[j];
    }

    newstr[i] = '\0';
    return newstr;
}

int main()
{
    char *array1 = "Jeevan";
    char *array2 = "Ghimire";

    char *joined = join(array1, array2);
    
    puts(joined);

    if (joined != NULL)
    {
        free(joined);
    }

    return 0;
}
