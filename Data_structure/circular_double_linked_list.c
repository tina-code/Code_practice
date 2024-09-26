#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node;

Node* Newnode(int val){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void Addnode(Node **start,Node *node,int aftval){
    if(*start==NULL && aftval==-1){
        *start=node;
        (*start)->next=*start;
        (*start)->prev=*start;
        return;
    }
    else{
        if(aftval==-1){  //插在第一個位置
            node->next=*start;
            node->prev=(*start)->prev;
            node->next->prev=node;
            node->prev->next=node;
            *start=node;
            return;
        }
        Node *current=*start;
        do{
            if(current->data==aftval){
                node->next=current->next;
                node->next->prev=node;
                node->prev=current;
                node->prev->next=node;
                return;
            }
            current=current->next;
        }while(current!=*start);
    }
}

void Deletenode(Node **start,int val){
    Node *tmp;
    Node *current=*start;
    if((*start)->data==val){   //刪除頭節點
        tmp=*start;
        current->prev->next=current->next;
        current->next->prev=current->prev;
        *start=current->next;
        free(tmp);
        return;
    }
    do{
        if(current->data==val){
            tmp=current;
            current->prev->next=current->next;
            current->next->prev=current->prev;
            free(tmp);
            return;
        }
        current=current->next;
    }while(current!=*start);
}

void Printlist(Node *start){
    Node *current=start;
    do{
        printf("%d ",current->data);
        current=current->next;
    }while(current!=start);
    printf("\n");
}

void Freelist(Node *start){  //可能有dangling pointer的情況,ex:free完list仍嘗試存取釋放記憶體後的內容，印出head->data
    Node *current=start;     //free完後，head依然存著釋放後node的位址，但這個位址是無效的，所以無法安全的訪問它
    Node *tmp;
    do{
        tmp=current;
        current=current->next;
        free(tmp);
    }while(current!=start); 
}

int main(){
    Node *head=NULL;
    Addnode(&head,Newnode(30),-1);
    Addnode(&head,Newnode(20),-1);
    Addnode(&head,Newnode(10),-1);
    Addnode(&head,Newnode(40),30);
    Addnode(&head,Newnode(25),20);
    Deletenode(&head,20);
    Addnode(&head,Newnode(15),10);
    Printlist(head);
    printf("%x\n",*head);  //--(1)
    printf("%d\n",head->data);
    Freelist(head);
    printf("%x\n",*head);  //--(2) (1)==(2)仍存著原node data=10的位址
    return 0;
}