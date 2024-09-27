#include <stdio.h>
#include <stdlib.h>

/*stack主要function包含isEmpty,Push,Pop,getTop,Size*/

typedef struct node{
    int data;
    struct node *next;
}Node; 

typedef struct stack{
    Node *top;
}Stack;

void init_stack(Stack *s){
    s->top=NULL;
}

int isEmpty(Stack *s){
    return s->top==NULL;
}

void Push(Stack *s,int val){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=s->top;
    s->top=newnode;
}

int Pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return -1;
    }
    Node *tmp=s->top;
    int item=tmp->data;
    s->top=s->top->next;
    free(tmp);
    return item;
}

int getTop(Stack *s){
    return s->top->data;
}

int Size(Stack *s){
    int cnt=0;
    Node *current=s->top;
    while(current!=NULL){
        cnt++;
        current=current->next;
    }
    return cnt;
}

int main(){
    Stack stack;
    init_stack(&stack);
    for(int i=0;i<100;i++){
        Push(&stack,i+1);
    }
    printf("%d\n",Pop(&stack));
    printf("%d\n",Pop(&stack));
    printf("%d\n",Pop(&stack));
    printf("size of stack: %d,top element= %d\n",Size(&stack),getTop(&stack));
    return 0;
}