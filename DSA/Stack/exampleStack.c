#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100
typedef struct {
    int *stackData;
    int MaxSize;
    int size;
}stack;

stack *create_stack(int stackCapacity){
    if(stackCapacity<=0) return NULL; //check weather size is 0 or not
    stack *stack  = malloc(sizeof(stack)); // allocate memory to stack 
    if(stack == NULL ) return NULL; // conditional checking
    stack->stackData = malloc(sizeof(int)* stackCapacity);    // allocate memory to stackData inside stack 
    if(stack->stackData == NULL) 
    {
    free(stack);
    return NULL;    
    }
    stack->MaxSize = stackCapacity;
    stack->size = 0;
    return stack; 
}

void distory_stack(stack *stack){
    free(stack->stackData);
    free(stack);
}

bool is_full(stack *stack){
    return stack->size == stack->MaxSize;
}
bool is_empty(stack *stack){
    return stack->size == 0;
}
bool pop(stack *stack, int *item) {
    if (is_empty(stack)) return false;
    *item = stack->stackData[--stack->size];
    return true;
}

bool push(stack *stack, int item) {
    if (is_full(stack)) return false;
    stack->stackData[stack->size] = item;
    stack->size++;
    return true;
}

bool peek(stack *stack, int *item) {
    if (is_empty(stack)) return false;
    *item = stack->stackData[stack->size - 1];
    return true;
}




int main()
{
    stack *stack  = create_stack(5);
    if (stack == NULL) {
        printf("Error creating stack\n");
        return 1;
    }
    if(is_empty(stack)) printf("Is empty \n");
    push(stack,2);
    push(stack,4);
    push(stack,7);
    push(stack,256);
    push(stack,29);
    if(is_full(stack)) printf("Stack is full:\n");
    printf("stack size %d\n",stack->size);
    distory_stack(stack);
return 0;
}