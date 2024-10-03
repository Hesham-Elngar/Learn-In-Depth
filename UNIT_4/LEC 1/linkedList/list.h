#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void insert_node_at_beginning(node** ptr,int val);
void insert_node_at_end(node** ptr,int val);
void insert_node_after(node** ptr,int val,int pos);
void delete_node_at_beginning(node** ptr);
void delete_node_at_pos(node** ptr,int pos);
void display_node(node* ptr);


#endif // _LIST_H_

