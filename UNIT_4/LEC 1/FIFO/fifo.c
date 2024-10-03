#include"fifo.h"

void init_queue(queue* q){
    q->counter=0;
    q->front=0;
    q->rear=-1;
}
void enqueue(int val,queue* q){
    if(!isFull(q)){
        q->rear=(q->rear+1)%MAX_SIZE;
    q->array[q->rear]=val;
    printf("%d has been added\n",val);
    (q->counter)++;
    }
    else{
        printf("FULL!!\n");
    }
}
void dequeue(queue* q){
    if(!isEmpty(q)){
        int x=q->array[q->front];
    printf("%d has been deleted\n",x);
    q->front=(1+q->front)%MAX_SIZE;
    (q->counter)--;
    }
    else{
        printf("EMPTY!!\n");
    }
}
int isFull(queue *q){
    return q->counter==MAX_SIZE;
}
int isEmpty(queue *q){
    return q->counter==0;
}
void display(queue *q){
    if(!isEmpty(q)){
        for(int i=q->front;i!=(q->rear)+1;i++){
                if(i>=MAX_SIZE) i%=MAX_SIZE;
            printf("%d ",q->array[i]);
        }
        printf("\n");
    }
    else{
        printf("EMPTY!!!\n");
    }
}
