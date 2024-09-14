#include"lifo.h"

LIFO_t lifo_obj;
int main()
{
    Lifo_Init(&lifo_obj);
    push(&lifo_obj,11);
    push(&lifo_obj,22);
    push(&lifo_obj,33);
    push(&lifo_obj,44);
    push(&lifo_obj,55);
    push(&lifo_obj,66);
    pop(&lifo_obj);
    pop(&lifo_obj);
    pop(&lifo_obj);
    pop(&lifo_obj);
    pop(&lifo_obj);
    pop(&lifo_obj);
    pop(&lifo_obj);
    return 0;
}
