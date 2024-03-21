#include <stdio.h>
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
int main()
{

  int Array_X[] = {0, 1, 2, 3};
  printf("\n%d\n", &Array_X[0]);
  printf("%d\n", Array_X);
  printf("\n%d\n", (Array_X + 1));

  return 0;
}