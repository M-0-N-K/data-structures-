#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node * prev;
};

struct node * push(struct node * top,int data){
    struct node * newNode=(struct node*)malloc(sizeof(struct node)); 
    newNode->data=data;
    newNode->prev=top;
    return newNode;
}

struct node * pop(struct node * top){
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=top->data;
    top=top->prev;
    temp->prev=top;
    return temp;
}

int search(struct node * top, int data){
    struct node * temp=top;
    int i=0;
    while(temp!=NULL){
        if( temp->data==data){
            return i;
        }
        temp=temp->prev;
        i++;
    }
    return -1;
}

void traverse(struct node * top){
    struct node * temp=top;
    while(temp!=NULL){
        printf("\n%d ",temp->data);
        temp=temp->prev;
    }
}

void main(){
    struct node * top =(struct node*)malloc(sizeof(struct node)); 
    top->prev=NULL;
    top->data=5;
    for(int i=0;i<5;i++){
        top=push(top,i);
    }
    
    for(int i=0;i<3;i++){
        struct node * newTop = pop(top);
        printf("\n popped element %d \n",newTop->data);
        top=newTop->prev;
    }
    printf("\nsearch results for element 5 :   %d\n", search(top,5));
}
