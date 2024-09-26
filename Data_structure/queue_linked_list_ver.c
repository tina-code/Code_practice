#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*queue主要function包含isEmpty,Enqueue,Dequeue,getFirst,getLast,Size*/

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct queue{
    Node *front,*rear;
}Queue;

void init_queue(Queue *q){
    q->front=q->rear=NULL;
}

int isEmpty(Queue *q){
    return q->front==NULL;
}

void Enqueue(Queue *q,int val){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;
    if(isEmpty(q)){
        q->front=q->rear=newnode;
    }
    else{
        q->rear->next=newnode;
        q->rear=newnode;
    }
}

int Dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    Node *tmp=q->front;
    int item=tmp->data;
    q->front=q->front->next;
    if(q->front==NULL){
        q->rear=NULL;
    }
    free(tmp);
    return item;
}

int getFirst(Queue *q){
    return q->front->data;
}

int getLast(Queue *q){
    return q->rear->data;
}

int Size(Queue *q){
    int cnt=0;
    Node *current=q->front;
    while(current!=NULL){
        cnt++;
        current=current->next;
    }
    return cnt;
}

int main(){
    Queue queue;
    init_queue(&queue);
    char command[100];
    int val;
    while(scanf("%s",command)){
        if(strcmp(command,"enqueue")==0){
            printf("Please enter the value to enqueue:");
            scanf("%d",&val);
            Enqueue(&queue,val);
        }
        else if(strcmp(command,"dequeue")==0){
            printf("%d\n",Dequeue(&queue));
        }
        else if(strcmp(command,"first")==0){
            printf("%d\n",getFirst(&queue));
        }
        else if(strcmp(command,"last")==0){
            printf("%d\n",getLast(&queue));
        }
        else{
            printf("size of queue: %d,first element= %d,last element= %d\n",Size(&queue),getFirst(&queue),getLast(&queue));
            printf("The end of the program.\n");
            break;
        }
    }
    return 0;
}