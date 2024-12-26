#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
        head        tail
            |        |
-     Null<-4<-5<-6<-7
*/

typedef struct Node
{
    int value;
    struct Node *next;

} NodeIndicator;

typedef struct
{
    NodeIndicator *head;
    NodeIndicator *tail;
    int size;
} Queue;

Queue *create_queue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue ->tail = NULL;
    queue->size = 0;
    return queue;
}

int size(Queue *queue){
    return queue->size;
}
bool is_empty(Queue *queue){
    return queue->size == 0;
}
int peek(Queue *queue,bool *status){
    if(is_empty(queue)) {
        *status = false;
    }
    *status = true;
    return  queue->head ->value;

}
void enqueue(Queue *queue,int value){
    NodeIndicator *newNode = malloc(sizeof(NodeIndicator));
    newNode->value = value;
    newNode->next = NULL;
    if (is_empty(queue))
    {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}
int dequeue(Queue *queue, bool *status){
    if (is_empty(queue))
    {
        *status = false;
    }
    *status = true;
    int value = queue->head->value;
    // deleting the value
    NodeIndicator *oldHead = queue->head;
    if (queue->size == 1)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
    queue->head = queue->head->next;
    free(oldHead);
    queue->size--;
    return value;
}
void destroy_Queue(Queue *queue)
{
    NodeIndicator *current_node = queue->head;
    while (current_node != NULL)
    {
        NodeIndicator *temp = current_node;
        current_node = current_node->next;
        free(temp);
    }
    free(queue);
}

int main()
{
    Queue *queue = create_queue();

    enqueue(queue, 4);
    if (!is_empty(queue))
    {
        printf("Queue is not empty \n");
    }
    else
    {
        printf("Queue is empty\n");
    }
    enqueue(queue, 5);
    enqueue(queue, 6);
    printf("Queue Size: %d\n", size(queue));
    bool status = false;
    int value = 0;
    value = peek(queue, &status);
    if (status == true)
        printf("Peek sucessful: %d\n", value);
    value = dequeue(queue, &status);
    if (status)
        printf("Dequeue is sucessful: %d\n", value);
    if (status == true)
        printf("Peek sucessful: %d\n", value);
    value = dequeue(queue, &status);
    if (status)
        printf("Dequeue is sucessful: %d\n", value);
    destroy_Queue(queue);
    return 0;
}