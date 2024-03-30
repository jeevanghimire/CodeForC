#include <stdio.h>

void transpose(int matrix[][20], int n);

int main()
{
  int n;
  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  int matrix[20][20];

  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }

  printf("Original Matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  transpose(matrix, n);

  printf("Transposed Matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}

void transpose(int matrix[][20], int n)
{
  int temp;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      
      temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
      
    }
  }
}