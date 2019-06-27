#include<stdio.h>
#include<stdlib.h>



struct node{
	//represents a single element in  the linked list . the data part contains values to store in the node and 
	//the pointer next , contains the link to next element in the linked list. 
	int data;
	struct node * next;
};



void show(struct node *start){
	//print all elements of a linked list from *start. 
	struct node *end;
	end=start;
	while(end!=NULL){
		printf("%d\t%p\n",end->data,end->next);
		end=end->next;
	}
}



void insert(struct node *pos, int data){
	//insert data after *pos . 
	struct node *new  = (struct node*)malloc(sizeof(struct node)); 
	new->data=data;
	new->next=pos->next;
	pos->next=new;
}

void delete(struct node *pos){
	//delete element at pos
	struct node *next=pos->next;
	pos->next=pos->next->next;
	free(next);
}



struct node * search(struct node *start,int data){
	//search if an element exists in the linked list and return its location if it does.
	struct node *end=start;
	while(end!=NULL){
		if(end->data==data){
			return end;
		}
		end=end->next;
	}
	return NULL;
}



void main(){
	struct node start,new;
	start.data=0;
	start.next=NULL;
	struct node *end=&start;
	for(int i=1;i<10;i++){
		insert(end,i);
		end=end->next;
	}
	show(&start);	
	delete(&start);
	show(&start);
	printf("\n%p",search(&start,5));

}