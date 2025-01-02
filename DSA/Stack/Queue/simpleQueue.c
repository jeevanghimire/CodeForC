#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max 0xfffff
int Data[Max];
int queueIndex = 0;
int front = 0;
void push(int data){
    if(queueIndex < Max) {
        Data[queueIndex] = data;
        printf("Pushed element:%d\n",data);
        queueIndex++;
    } else {
        printf("Queue is full\n");
    }
}
int Pop(){
    if(front < queueIndex) {
        int data = Data[front];
        front++;
        return data;
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}
int main(){
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
