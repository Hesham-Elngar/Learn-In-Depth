#ifndef _LIFO_H
#define _LIFO_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
typedef unsigned int u32;

typedef struct {
    u32 size;
    u32 counter;
    u32 top;
    u32 base;
    u32 *buffer;
} LIFO_t;

typedef enum {
    empty,
    not_empty,
    full,
    not_full,
    no_error,
    error_state
} LIFO_Status_t;

LIFO_Status_t Lifo_Init(LIFO_t* lifo);
LIFO_Status_t push(LIFO_t* lifo, u32 value);
LIFO_Status_t pop(LIFO_t* lifo);
LIFO_Status_t top(LIFO_t* lifo, u32* top_value);
LIFO_Status_t destroy(LIFO_t* lifo);

#endif // _LIFO_H
