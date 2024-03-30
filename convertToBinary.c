#include <stdio.h>
#include <math.h>

int convertToBinary(int arr[],int n);
int main()
{
  int n;
  printf("Enter the number of binary digits:\n");
  scanf("%d", &n);
  int arr[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("The Decimal form is:%d",convertToBinary(arr,n));
return 0;
}

int convertToBinary(int arr[],int n){
  int power=0;
  int sum=0;
  for(int i = n-1;i>=0;i--){
    sum = sum + arr[i]*pow(2,power);
    power++;  
  }
  return sum;
}