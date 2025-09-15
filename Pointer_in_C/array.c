/*
1. Passing arguments to functions and returning values from functions
2. Passing Arguments to functions but no return value
3. No arguments to functions but return value
4. No arguments to functions and no return value
*/



#include <stdio.h>


int add(int a, int b);

void add1(int a, int b){
    int sum = a + b;
}

int add2(){
    int a = 10;
    int b = 20;
    int sum = a + b;
    return sum;
}
void add3(){
    int a = 10;
    int b = 20;
    int sum = a + b;
    printf("Sum is %d\n", sum);
}
int main()
{
    // function types
    int result = add(10, 20);
    printf("Sum is %d\n", result);
    add1(10, 20); // no return value
    int result2 = add2();
    printf("Sum is %d\n", result2);
    add3(); // no arguments and no return value

    return 0;
}


int add(int a, int b){
    return a + b;
}