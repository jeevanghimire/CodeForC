/*
        head        tail
            |        |
-     Null<-4<-5<-6<-7
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct Node
{
    int value;
     struct Node *next;

}Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
}Queue;

Queue *create_queue(){
    Queue *queue = (sizeof(Queue)); 
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
        return NULL;
    }
    *status = true;
    return  queue->head ->value;

}
void enqueue(Queue *queue,int value){
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    queue->tail->next = newNode;
}
int dequeue(Queue *queue, bool *status){

}
void destroy_Queue(Queue *queue){}


int main()
{
    
return 0;
}