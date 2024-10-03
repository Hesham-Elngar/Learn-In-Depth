#include"list.h"

void insert_node_at_beginning(node** ptr,int val){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=val;
    if(*ptr==NULL){
        newNode->next=NULL;
        *ptr=newNode;
    }
    else{
        newNode->next=*ptr;
        *ptr=newNode;
    }
}

void insert_node_at_end(node** ptr,int val){
    node* newNode=(node*)malloc(sizeof(node));
    node* temp=*ptr;
    newNode->data=val;
    newNode->next=NULL;
    if(temp==NULL){
        *ptr=newNode;
    }
    else{
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    }
}

void insert_node_after(node** ptr,int val,int pos){
    node* newNode=(node*)malloc(sizeof(node));
    node* temp=*ptr;
    newNode->data=val;
    while(--pos){
       temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void delete_node_at_beginning(node** ptr){
    node* temp=*ptr;
    if(temp==NULL) printf("empty\n");
    else{
    *ptr=temp->next;
    free(temp);
}
}

void delete_node_at_pos(node** ptr,int pos){
    node* temp=*ptr;
    node* pre=(node*)malloc(sizeof(node));
    while(--pos){
        pre=temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    free(temp);
}

void display_node(node* ptr){
    node* temp=ptr;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


