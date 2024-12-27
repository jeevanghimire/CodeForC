
/*
    
        push
pop <-   |
      |  |   
            5 <-- peek   
            3
            2
            1
*/




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    int MaxSize;
    int *StackElement; // 
    int size;
}Stack;

Stack *create_stack(int Capacity){
    if(Capacity<0) return NULL;
    Stack *stack = malloc(sizeof(stack)); //allocate memory to stack
    if(stack==NULL) return NULL;
    stack->StackElement = malloc(sizeof(stack)*Capacity);//allocating memory for storing stack elements
    if(stack->StackElement == NULL)
    {
        free(stack);
        return NULL;
    }
    stack->MaxSize = Capacity;
    stack->size = 0;
    return stack;

}
void distory_stack(Stack *stack){
    free(stack->StackElement);
    free(stack);

}
bool is_empty(Stack *stack){
    return stack->size == 0;
}
bool is_full(Stack *stack){
    return stack->size == stack->MaxSize;
}
bool push(Stack *stack, int data){
    if(is_full(stack)) return false;
    stack->StackElement[stack->size] = data;
    stack->size++;
    return true;
}
bool pop(Stack *stack, int *data){
    if(is_empty(stack)) return false;
    *data = stack->StackElement[stack->size - 1];
    stack->size--;
    return true;
}
bool peek(Stack *stack, int *data){
    if(is_empty(stack)) return false;
    *data = stack->StackElement[stack->size - 1];
    return true;
}


int main(){
Stack stack;
    int max_size = 5;
    stack.StackElement = (int *)malloc(max_size * sizeof(int));
    stack.size = 0;
    stack.MaxSize = max_size;
    // Push elements onto the stack
    int element;
    for (int i = 0; i < max_size; i++) {
        printf("Enter element to push: ");
        scanf("%d", &element);
        if (!push(&stack, element)) {
            printf("Stack is full. Cannot push %d\n", element);
        }
    }

    // Peek at the MaxSize element
    int top_element;
    if (peek(&stack, &top_element)) {
        printf("Top element is %d\n", top_element);
    } else {
        printf("Stack is empty\n");
    }

    // Pop elements from the stack
    int popped_element;
    char choice;
    while (true) {
        if (pop(&stack, &popped_element)) {
            printf("Popped element is %d\n", popped_element);
        } else {
            printf("Stack is empty. Cannot pop.\n");
            break;
        }
        printf("Do you want to pop another element? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    // Check if the stack is empty
    if (is_empty(&stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    // Free allocated memory
    free(stack.StackElement);

    return 0;
}
