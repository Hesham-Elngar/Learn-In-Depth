#include "lifo.h"

static LIFO_Status_t is_full(LIFO_t* lifo)
{
    return (lifo->size == lifo->counter) ? full : not_full;
}

static LIFO_Status_t is_empty(LIFO_t* lifo)
{
    return (lifo->counter == 0) ? empty : not_empty;
}

LIFO_Status_t Lifo_Init(LIFO_t* lifo)
{
    LIFO_Status_t state = error_state;
    if (lifo != NULL)
    {
        lifo->buffer = (u32*)malloc(sizeof(u32) * MAX_SIZE);
        if (lifo->buffer != NULL)
        {
            state = no_error;
            lifo->top = -1;
            lifo->base = 0;
            lifo->size = MAX_SIZE;
            lifo->counter = 0;
        }
    }
    return state;
}

LIFO_Status_t push(LIFO_t* lifo, u32 value)
{
    if (lifo == NULL)
    {
        return error_state;
    }
    if (is_full(lifo) == full)
    {
        printf("full\n");
        return full;
    }
    else
    {
        lifo->buffer[++lifo->top] = value;
        lifo->counter++;
        printf("%d added\n", value);
    }
    return no_error;
}

LIFO_Status_t pop(LIFO_t* lifo)
{
    if (lifo == NULL)
    {
        return error_state;
    }
    if (is_empty(lifo) == empty)
    {
        printf("empty\n");
        return empty;
    }
    else
    {
        printf("%d popped\n", lifo->buffer[lifo->top--]);
        lifo->counter--;
    }
    return no_error;
}

LIFO_Status_t top(LIFO_t* lifo, u32* top_value)
{
    if (lifo == NULL || top_value == NULL)
    {
        return error_state;
    }
    if (is_empty(lifo) == empty)
    {
        printf("empty\n");
        return empty;
    }
    else
    {
        *top_value = lifo->buffer[lifo->top];
    }
    return no_error;
}

LIFO_Status_t destroy(LIFO_t* lifo)
{
    if (lifo == NULL)
    {
        return error_state;
    }
    free(lifo->buffer);
    lifo->buffer = NULL;
    return no_error;
}
