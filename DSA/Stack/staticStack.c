// Implementing Static Stack using an Array in C

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

int main()
{
    struct Stack *stack = createStack(3);

    while (1)
    {
        printf("Enter the choice of operation\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        int choice, item;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &item);
            push(stack, item);
            break;
        case 2:
            printf("Popped element: %d\n", pop(stack));
            break;
        case 3:
            printf("Top element: %d\n", peek(stack));
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

