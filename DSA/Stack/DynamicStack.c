#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Stack
{
    int top;
    int data;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->data = 0;
    stack->top = -1;
    stack->array = (int *)malloc(stack->data * sizeof(int));
    return stack;
}

bool isFull(struct Stack *stack)
{
    return stack->top == stack->data - 1;
}

bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        stack->data++;
        stack->array = (int *)realloc(stack->array, stack->data * sizeof(int));
        stack->array[++stack->top] = item;
        printf("%d pushed to stack\n", item);
    }
    else
    {
        stack->array[++stack->top] = item;
        printf("%d pushed to stack\n", item);
    }
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
    struct Stack *stack = createStack(1);

    //asking user to enter the number of elements to be pushed
    int choice, item;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &item);
            push(stack, item);
            break;
        case 2:
            item = pop(stack);
            if (item != -1)
            {
                printf("Popped element: %d\n", item);
            }
            break;
        case 3:
            item = peek(stack);
            if (item != -1)
            {
                printf("Top element: %d\n", item);
            }
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

