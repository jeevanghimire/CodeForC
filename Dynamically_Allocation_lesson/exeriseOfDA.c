
#include <stdio.h>
#include <stdlib.h>
#define Newline printf("\n");

double sumOfElement(double *array, int numb)
{
    double sum = 0.0;  // Initialize sum to 0
    for (int i = 0; i < numb; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

int main()
{
    int numb, i;
    printf("How many numbers do you want to allocate: \n");
    scanf("%d", &numb);

    double *array = (double *)malloc(numb * sizeof(double));
    if (array == NULL)
    {
        printf("Allocation failed.\n");
        exit(1);
    }

    printf("Enter %d numbers:\n", numb);
    for (i = 0; i < numb; i++)
    {
        scanf("%lf", &array[i]);  // Use %lf for double
    }

    printf("Sum of the elements is %f\n", sumOfElement(array, numb));

    if (array != NULL)
    {
        free(array);
    }

    return 0;
}

