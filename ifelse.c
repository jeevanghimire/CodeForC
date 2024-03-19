#include <stdio.h>

// Function to generate the nth Fibonacci term
int fibonacci(int n) {
    int a = 0 , b = 1 , c;
    if (n <= 1)
        return n;
    else
    for (int i = 0;i<n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1)
        return 0;
    if(num%2==0){
        
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int fib = fibonacci(n);
    printf("The %dth Fibonacci term is: %d\n", n, fib);

    if (isPrime(fib))
        printf("The %dth Fibonacci term is a prime number.\n", n);
    else
        printf("The %dth Fibonacci term is not a prime number.\n", n);

    return 0;
}