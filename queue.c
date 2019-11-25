#include<stdio.h>
#include<stdlib.h>

struct node {
    //the building block of a queue.
    int data;
    struct node * next;
};

struct node * insert(struct node * tail,int data){
    //takes the tail of a queue and puts a new node at the end of it.
    //returns new tail.
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=data;
    tail->next=temp;
    tail=temp;
    return tail;
}

struct node * delete(struct node * head){
    //takes the head of a queue and deletes one element from head.
    //returns new head.
    struct node * temp=head;
    head=head->next;
    free(temp);
    return head;
}


int search(struct node * head,int data){
    //search for index of data from head 0 based counting
    //returns the 0 based index of first occurence of data. counting from head.
    int i=0;
    struct node * temp=head;
    while(temp!=NULL){
        if(temp->data=data){
            return i;
        }
        ++i;
        temp=temp->next;
    }
        return -1;
}

void traverse(struct node* head){
    //takes the head of a queue and prints all elements of it.
    struct node * temp=head;
    while(temp!=NULL){
        printf("\n %d ",temp->data);
        temp=temp->next;
    }
}

void main(){
    struct node * head=(struct node*)malloc(sizeof(struct node));
    struct node * tail=head;
    head->data=0;
    head->next=NULL;
    printf("\n inserting some elements \n ");
    for(int i=1;i<10;i++){
        tail=insert(tail,i);
    }
    traverse(head);
    printf("\ndeleting some elements\n");
    for(int i=0;i<4;i++){
       head=delete(head);
    }
    printf("\n traversing \n");
    traverse(head);
    printf("\n searching for 5   ");
    printf("%d",search(head,4));
}