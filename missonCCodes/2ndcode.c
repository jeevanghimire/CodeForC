#include <stdio.h>

int main() 
{
    int r1, c1, r2, c2, i, j, k;
    printf("Enter the size of matrix of R1 and C1:\n");
    scanf("%d%d", &r1, &c1);
    printf("Enter the size of matrix of R2 and C2:\n");
    scanf("%d%d", &r2, &c2);
    
    if (c1 != r2) {
        printf("Matrix multiplication not possible: Column count of first matrix must match row count of second matrix.\n");
        return 1;
    }

    int MatA[r1][c1], MatB[r2][c2], ResMat[r1][c2];

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &MatA[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("Enter b%d%d: ", i + 1, j + 1);
            scanf("%d", &MatB[i][j]);
        }
    }

    // Matrix multiplication
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            ResMat[i][j] = 0;
            for (k = 0; k < c1; k++) {
                ResMat[i][j] += MatA[i][k] * MatB[k][j];
            }
        }
    }

    // Printing the result matrix
    printf("Resultant matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", ResMat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
