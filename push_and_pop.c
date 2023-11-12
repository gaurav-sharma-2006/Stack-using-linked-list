#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
//traversing a list
void traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
//checking the stack is empty or not
int isempty(struct node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//checking the stack in full or not
int isfull(struct node *top){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//insert an element into stack
struct node *push(struct node *top,int data){
    if(isfull(top)){
        printf("Stack overflow\n");
    }
    else{
        struct node *ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->next=top;
        top=ptr;
        return top;
    }
}
//delete an element from a stack
struct node *pop(struct node** top){
    if(isempty(*top)){
        printf("Stack underflow");
    }
    else{
        struct node *n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
int main(){
    struct node *top=NULL;
    printf("Before deletion\n");
    top=push(top,89);
    top=push(top,85);
    top=push(top,99);
    top=push(top,39);
    top=push(top,859);
    top=push(top,849);
    traversal(top);

    printf("\n\n");

    printf("After deletion\n");
    printf("Popped element is %d:-",pop(&top));
    traversal(top);
}