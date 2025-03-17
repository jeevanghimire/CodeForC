//calculate sum of fib series using recursion

#include <stdio.h>
int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
int fraction(int n){
    if(n == 0){
        return 1;
    }
    else{ 
        return n * fraction(n-1);
    }
}
int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("The factorial of %d is %d\n",n,fraction(n));
    printf("The sum of the fibonacci series is: %d\n", fib(n));
return 0;
}