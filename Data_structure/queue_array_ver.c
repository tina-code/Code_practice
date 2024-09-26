#include <stdio.h>
#define MAX 100

/*queue主要function包含isEmpty,isFull,Enqueue,Dequeue,getFirst,getLast,Size*/

typedef struct{
    int item[MAX];
    int front,rear;
}Queue;

void init_queue(Queue *q){
    q->front=-1;
    q->rear=-1;
}

int isEmpty(Queue *q){
    return q->front==-1 || q->front > q->rear;
}

int isFull(Queue *q){
    return q->rear==MAX-1;
}

int getFirst(Queue *q){
    return q->item[q->front];
}

int getLast(Queue *q){
    return q->item[q->rear];
}

int Size(Queue *q){
    if(isEmpty(q)){
        return 0;
    }
    return q->rear - q->front;
}

void Enqueue(Queue *q,int val){
    if(isFull(q)){
        printf("Queue is Full!\n");
    }
    else{
        if(q->front==-1){
            q->front=0;
        }
        q->item[++(q->rear)]=val;
    }
}

int Dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return -1;
    }
    else{
        return q->item[(q->front)++];
    }
}

int main(){
    Queue queue;
    init_queue(&queue);
    for(int i=0;i<100;i++){
        Enqueue(&queue,i+1);
    }
    Enqueue(&queue,101);
    printf("%d\n",Dequeue(&queue));
    printf("size of queue: %d,first element= %d,last element= %d\n",Size(&queue),getFirst(&queue),getLast(&queue));
    return 0;
}