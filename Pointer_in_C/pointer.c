#include <stdio.h>
void sort(float *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main()
{
    int a = 10, b = 20;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    float arr[] = {2.3, 4.5, 1.2, 3.4, 5.6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);
    printf("Array in ascending order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%f ", arr[i]);
    }
    return 0;
}