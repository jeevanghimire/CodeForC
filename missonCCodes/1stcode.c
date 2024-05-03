/*
!                   arr          j
!                     |          |
!   arr[size] == [1,2,3,4,5,6,7,..n]
!   int arr[size];
        arr[2] == *(arr+2)
*/

#include <stdio.h>
int main()
{
    int arr[5] = {1,2,3,4,5};
    printf("%d\n",arr[2]);
    printf("%d\n",*(arr+2));

return 0;
}