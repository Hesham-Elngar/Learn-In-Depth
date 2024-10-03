#ifndef _FIFO_H_
#define _FIFO_H_

#include<stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

 typedef struct {
    int front;
    int rear;
    int counter;
    int array[MAX_SIZE];
}queue;


void init_queue(queue* q);
void enqueue(int val,queue* q);
void dequeue(queue* q);
int isFull(queue *q);
int isEmpty(queue *q);
void display(queue *q);


#endif // _FIFO_H_
