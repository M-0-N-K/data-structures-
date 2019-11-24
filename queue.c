#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * insert(struct node * tail,int data){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=data;
    tail->next=temp;
    tail=temp;
    return tail;
}

struct node * delete(struct node * head){
    struct node * temp=head;
    head=head->next;
    free(temp);
    return head;
}


int search(struct node * head,int data){
    //search for index of data from head 0 based counting
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