#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define returnNULL 0

typedef struct Node
{
  int Data;
  struct Node *Next;
} Node_t;

typedef struct
{
  Node_t *Head;
  Node_t *Tail;
  int size;
} Queue;

Queue *CreateQueue()
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->Head = NULL;
  q->Tail = NULL;
  q->size = 0;
  return q;
}
int size(Queue *q)
{
  return q->size;
}

bool isEmpty(Queue *q)
{
  return q->size == 0;
}
int peek(Queue *q, bool *status)
{
  if (isEmpty(q))
  {
    *status = false;
    return 0;
  }
  return q->Head->Data;
}
void enqueue(Queue *q, int value)
{
  Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
  newNode->Data = value;
  newNode->Next = NULL;
  if (isEmpty(q))
  {
    q->Head = newNode;
    q->Tail = newNode;
  }
  else
  {
    q->Tail->Next = newNode;
    q->Tail = newNode;
  }
  q->size++;
}
int dequeue(Queue *q, bool *status)
{
  if (isEmpty(q))
  {
    *status = false;
    return returnNULL;
  }
  *status = true;
  int value = q->Head->Data;
  // delet the value
  Node_t *oldHead = q->Head;
  if (q->size == 1)
  {
    q->Head = NULL;
    q->Tail = NULL;
  }
  else
  {
    q->Head = q->Head->Next;
  }
  q->size--;
  free(oldHead);
  return value;
}
void DestoryQueue(Queue *q)
{
  Node_t *current = q->Head;
  while (current != NULL)
  {
    Node_t *temp = current;
    current = current->Next;
    free(temp);
  }
  free(q);
}

int main(void)
{

  Queue *q = CreateQueue();
  enqueue(q, 10);
  if (!isEmpty(q))
  {
    printf("Queue is not empty\n");
  }
  else
  {
    printf("Queue is empty\n");
  }
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);
  printf("Queue size is %d\n", size(q));

  bool status = false;
  int value = 0;
  value = peek(q, &status);
  if (status)
    printf("Peek Value: %d\n", value);
  else
    printf("Peek is Empty\n");

  value = dequeue(q, &status);
  if (status)
  {
    printf("Dequeue SucessFull: %d\n", value);
  }
  else
  {
    printf("\nDequeue UnSucessfull\n");
  }

  return 0;
}