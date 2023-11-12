#include <stdio.h>
#include <stdlib.h>
#define Newline (printf("\n"));
void print_loop(int *array, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    Newline
}
int main()
{
    int numb, i, j, AddedNumber;
    char count;
    printf("Enter the number of interger:\n");
    scanf("%d", &numb);
    int *number = (int *)malloc(numb * sizeof(int));
    if (number == NULL)
    {
        printf("Allocation Failed bro:<(\n");
        exit(1);
    }
    for (i = 0; i < numb; i++)
    {
        scanf("%d", &number[i]);
    }
    printf("Before ReAllocation:\n");

    print_loop(number, numb);

    printf("Do you want to add more number :\n");
    scanf("%d", &AddedNumber);
    int *temp = realloc(number, (numb + AddedNumber) * sizeof(int));
    if (temp == NULL)
    {
        printf("Reallocatio  Failed bro:<(\n");
        free(number);
        exit(2);
    }
    else
    {
        number = temp;
    }
    for (i = 0; i < (numb + AddedNumber); i++)
    {
        scanf("%d", &number[i]);
    }

    printf("Without Reallocation of memeory:\n");
    print_loop(number, numb);

    printf("After Allocation of Memory:\n");
    print_loop(number, numb + AddedNumber);
    if (number != NULL)
    {
        free(number);
    }
    return 0;
}