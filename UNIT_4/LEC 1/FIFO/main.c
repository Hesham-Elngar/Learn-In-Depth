#include"fifo.h"
int main()
{
    queue q;
    init_queue(&q);
    enqueue(11,&q);
    enqueue(22,&q);
    enqueue(33,&q);
    enqueue(44,&q);
    enqueue(55,&q);
    enqueue(66,&q);
    display(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(&q);
    enqueue(1,&q);
    enqueue(2,&q);
    enqueue(3,&q);
    enqueue(4,&q);
    enqueue(5,&q);
    display(&q);




    return 0;
}
