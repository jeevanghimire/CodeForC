#include <stdio.h>

#define MAX_SIZE 10
void resultOfFunction(int m, int q, int C[10][10]) {
  printf("Resultant matrix C:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
}
void matrixMultiplication(int A[][MAX_SIZE], int B[][MAX_SIZE],
                          int C[][MAX_SIZE], int m, int n, int p, int q) {
  if (n != p) {
    printf("Matrix multiplication not possible!\n");
    return;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < q; j++) {
      C[i][j] = 0;
      for (int k = 0; k < n; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

int main() {
  int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
  int m, n, p, q;

  printf("Enter the number of rows and columns of matrix A: ");
  scanf("%d %d", &m, &n);

  printf("Enter the elements of matrix A:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
    }
  }

  printf("Enter the number of rows and columns of matrix B: ");
  scanf("%d %d", &p, &q);

  printf("Enter the elements of matrix B:\n");
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < q; j++) {
      scanf("%d", &B[i][j]);
    }
  }

  matrixMultiplication(A, B, C, m, n, p, q);

  resultOfFunction(m, q, C);

  return 0;
}
