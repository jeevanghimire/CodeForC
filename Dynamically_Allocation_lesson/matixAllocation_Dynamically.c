#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, m;
    printf("Enter the  no of row and colume:\n");
    scanf("%d %d", &n, &m);
    int *mat = (int *)malloc(n * m * sizeof(int));
    if (mat == NULL)
    {
        printf("Allocate vaxaina memory khyal gaar\n");
        exit(1);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the number : \n");
            scanf("%d", &mat[n * i + j]);
        }
    }

    // printing the matrix
    printf("\n-----------------------------------------------------------------------------\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mat[n * i + j]);
        }
        printf("\n");
    }

    if (mat != NULL)
    {
        free(mat);
    }
return 0;
}
