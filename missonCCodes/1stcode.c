#include<stdio.h>
	
	void sum (int *a , int *b,int *sum);
	int main()
	{
		int a = 10 , b = 20, Sum = 0;
    sum(&a,&b,&sum);
    printf("The sum is %d \n", sum);
		return 0;
	}
void sum (int *a , int *b,int *Sum){
    *Sum = *a + *b; 
}