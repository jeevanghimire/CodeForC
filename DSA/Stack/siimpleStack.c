#include <stdio.h>
#define Max 0xfffffff // size = 16^6 - 1
int array[Max];
int cap = 0;
void push(int data)
{
    array[cap] = data;
    printf("Pushed %d\n", data);
    cap++;
}
int Pop()
{
    int res;
    res = array[cap - 1];
    cap--;
    return res;
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printf("|------|\n");
    printf("Popped %d\n", Pop());
    printf("Popped %d\n", Pop());
    printf("Popped %d\n", Pop());
    printf("Popped %d\n", Pop());
    printf("Popped %d\n", Pop());
    return 0;
}