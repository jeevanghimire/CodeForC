#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n, i, j,count=0;
    printf("Enter the row and Colume:\n");
    scanf("%d %d", &m, &n);
    int *mat = (int *)malloc((m * n) * sizeof(int));
    if (mat == NULL)
    {
        printf("Allocation Failed:\n");
        exit(1);
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[n * i + j]);
        }
    }
    // printing The Matrix
    printf("--------------------------------------------------\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", mat[m * i + j]);
        }
        printf("\n");
    }
    printf("--------------------------------------------------\n");
    // Developing Logic
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(mat[m*i+j]==0){
                count = count + 1;
            }
        }
    }
    printf("The number of zeros are:\n");
    printf("%d \n",count);
    if (mat != NULL)
    {
        free(mat);
    }
    return 0;
}