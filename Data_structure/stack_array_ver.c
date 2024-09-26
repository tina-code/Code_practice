#include <stdio.h>
#define MAX 100

/*stack主要function包含isEmpty,isFull,Push,Pop,getTop,Size*/

typedef struct{
    int data[MAX];
    int top;
}Stack;

void init_stack(Stack *s){
    s->top=-1;
}

int isFull(Stack *s){
    return s->top==MAX-1;
}

int isEmpty(Stack *s){
    return s->top==-1;
}

int getTop(Stack *s){
    return s->data[s->top];
}

int Size(Stack *s){
    return s->top+1;
}

void push(Stack *s,int val){
    if(isFull(s)){
        printf("Stack is full!\n");
    }
    else{
        s->data[++(s->top)]=val;
    }
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return -1;
    }
    else{
        return s->data[(s->top)--];
    }
}

int main(){
    Stack stack1;
    init_stack(&stack1);
    for(int i=0;i<100;i++){
        push(&stack1,i+1);
    }
    printf("%d\n",pop(&stack1));
    printf("%d\n",pop(&stack1));
    printf("%d\n",pop(&stack1));
    printf("size of stack: %d,top element= %d\n",Size(&stack1),getTop(&stack1));

    return 0;
}