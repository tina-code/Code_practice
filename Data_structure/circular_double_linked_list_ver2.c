#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

void add_node(Node **start,int val){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(*start==NULL){
        *start=newnode;
        (*start)->next=*start;
        (*start)->prev=*start;
        return;
    }
    else{
        Node *current=*start;
        while(current->next!=*start){
            current=current->next;
        }
        current->next=newnode;
        newnode->prev=current;
        newnode->next=*start;
        (*start)->prev=newnode;
        return;
    }
}

void insert_node(Node **start,int aftval,int val){
    Node *current=*start;
    do{
        if(current->data==aftval){
            Node *newnode=(Node*)malloc(sizeof(Node));
            newnode->data=val;
            newnode->next=NULL;
            newnode->prev=NULL;
            newnode->next=current->next;
            newnode->next->prev=newnode;
            current->next=newnode;
            newnode->prev=current;
            break;
        }
        current=current->next;
    }while(current!=*start);
}

void delete_node(Node **start,int val){
    Node *current=*start;
    Node *tmp;

    if(*start==NULL){  //空list則return
        return;
    }
    if((*start)->data==val){
        tmp=*start;
        if((*start)->next==*start){   //如果list只有一個節點
            *start==NULL;
        }
        else{
            *start=current->next;
            (*start)->prev=current->prev;
            (*start)->prev->next=*start;
        }
        free(tmp);
        return;
    }
    current=current->next;
    while(current!=*start){
        if(current->data==val){
            tmp=current;
            current->prev->next=current->next;
            current->next->prev=current->prev;
            free(tmp);
            return;
        }
        current=current->next;
    }
}

void printlist(Node *start){
    printf("The list: ");
    Node *current=start;
    do{
        printf("%d ",current->data);
        current=current->next;
    }while(current!=start);
    printf("\n");
}

void print_invlist(Node *start){
    printf("The inverse list: ");
    Node *current=start->prev;
    do{
        printf("%d ",current->data);
        current=current->prev;
    }while(current!=start->prev);
    printf("\n");
}

void freelist(Node **start){
    Node *current=*start;
    Node *tmp;
    do{
        tmp=current;
        current=current->next;
        free(tmp);
    }while(current!=*start);
    *start=NULL;
}

int main(){
    Node *head=NULL;
    add_node(&head,10);
    add_node(&head,20);
    add_node(&head,30);
    add_node(&head,40);
    add_node(&head,50);
    delete_node(&head,20);
    printlist(head);
    print_invlist(head);
    delete_node(&head,40);
    printlist(head);
    print_invlist(head);
    //delete_node(&head,50);
    insert_node(&head,30,40);
    insert_node(&head,10,20);
    printlist(head);
    print_invlist(head);
    freelist(&head);
    if(head==NULL){
        printf("Free list finish!\n");
    }
    //printf("size of a node %ld\n",sizeof(*head)); //因為64bit的作業系統裡，指標是8byte，所以會把int填補4byte對齊

    return 0;
}