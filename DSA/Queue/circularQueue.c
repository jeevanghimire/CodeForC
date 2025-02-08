#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #define SIZE 5

typedef struct {
    int MaxCap;
    int *items;
    int front;
    int rear;
} CircularQueue;

void initialize(CircularQueue *q, int MaxSize) {
    q->MaxCap = MaxSize;
    q->items = (int *)malloc(sizeof(int) * MaxSize);
    q->front = -1;
    q->rear = -1;
}

bool isFull(CircularQueue *q) {
    if ((q->front == 0 && q->rear == q->MaxCap - 1) || (q->front == q->rear + 1)) {
        return true;  // q->front == (q->front +1)%MaxCap;  this is better for bool
    }
    return false;
}

int isEmpty(CircularQueue *q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->MaxCap;
    q->items[q->rear] = value;
    printf("Inserted %d\n", value);
}

int dequeue(CircularQueue *q) {
    int element;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    element = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->MaxCap;
    }
    return element;
}

void display(CircularQueue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Front -> %d\n", q->front);
    printf("Items -> ");
    for (i = q->front; i != q->rear; i = (i + 1) % q->MaxCap) {
        printf("%d ", q->items[i]);
    }
    printf("%d\n", q->items[i]);
    printf("Rear -> %d\n", q->rear);
}

int main() {
    CircularQueue q;
    int sizeofQueue;
    scanf("%d",&sizeofQueue);
    initialize(&q,sizeofQueue);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    display(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    display(&q);

    enqueue(&q, 6);
    display(&q);

    return 0;
}