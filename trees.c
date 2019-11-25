#include<stdio.h>
#include<stdlib.h>

//implementing and understanding a simple binary tree. 

struct node {
    //the tree node has a data element, and two pointers, one to left child and one to right child.
    int data;
    struct node * rchild;
    struct node * lchild;
};

void inorderTraversal(struct node * root){
    if(root!=NULL){
    printf("%d - ",root->data);
    inorderTraversal(root->lchild);
    inorderTraversal(root->rchild);
    }
    return;
}

void preorderTraversal(struct node * root){
    if(root!=NULL){
    preorderTraversal(root->lchild);
    printf("%d - ",root->data);
    preorderTraversal(root->rchild);
    }
    return;
}
void postorderTraversal(struct node * root){
    if(root!=NULL){
    postorderTraversal(root->lchild);
    postorderTraversal(root->rchild);
    printf("%d - ",root->data);
    
    }
    return;
}


struct node * insert(struct node * root, int data){
    //if the element to insert is greater than root, it goes to right side of root, else to left side.
    if(root->data>data){
        if( root->lchild==NULL){
            struct node *newNode=(struct node *)malloc(sizeof(struct node));
            root->lchild=newNode;
            newNode->lchild=NULL;
            newNode->rchild=NULL;
            newNode->data=data;
            return newNode;
        }
        else{
            return insert(root->lchild,data);
        }
    }
    else{
        if(root->rchild==NULL){
            struct node *newNode=(struct node *)malloc(sizeof(struct node));
            root->rchild=newNode;
            newNode->lchild=NULL;
            newNode->rchild=NULL;
            newNode->data=data;
            return newNode;
        }
        else{
            return insert(root->rchild,data);
        }
    }
}

struct node * search(struct node * root,int data){
    if(root!=NULL){
        if(root->data==data){
            return root;
        }
        else if( root->data>data){
            return search(root->lchild,data);
        }
        else{
            return search(root->rchild,data);
        }
    }
    return NULL;
}

void main(){
    int elemCount,i=1,data;
    struct node * root=(struct node * )malloc(sizeof(struct node));
    printf("\ninsert the number of  elements you want in the tree");
    scanf("%d",&elemCount);

    printf("\nstart entering elements\n");
    scanf("%d",&data);

    //first element goes to root
    root->data=data;
    root->lchild=NULL;
    root->rchild=NULL;


    while(i<elemCount){
        scanf("%d",&data);
        struct node *newNode=insert(root,data);
        i++;
    }
    //inorder Traversal
    inorderTraversal(root);
    printf("\n");
    preorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    printf("doing a search on elements \n enter the element to search");
    scanf("%d",&data);
    struct node * temp=search(root,data);
    if(temp)
        printf("\n %d found at location %p",temp->data,temp);
    else
        printf("\n %d not found in tree\n",data);

}