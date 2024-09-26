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
    return;
  }
  else{
    Node *current=*start;
    while(current->next!=NULL){
      current=current->next;
    }
    current->next=newnode;
    newnode->prev=current;
    return;
  }
}

void printlist(Node *start){
  while(start!=NULL){
    printf("%d ",start->data);
    start=start->next;
  }
  printf("\n");
}
  
void insert_node(Node **start,int aftval,int val){
  Node *current=*start;
  while(current!=NULL){
    if(current->data==aftval){
      Node *newnode=(Node*)malloc(sizeof(Node));
      newnode->data=val;
      newnode->next=NULL;
      newnode->prev=NULL;
      if(current->next==NULL){
        current->next=newnode;
        newnode->prev=current;
        break;
      }
      else{
        newnode->next=current->next;
        current->next->prev=newnode;
        current->next=newnode;
        newnode->prev=current;
        break;
      }
    }
    current=current->next;
  }
}

void delete_node(Node **start,int val){  //start=&head (start是一個指向pointer的指標**,它存的是head的位址)
  Node *current=*start;                  //,如果要解引用取得head的內容,也就是節點的位址,如下*start=head;
  Node *tmp;
  if(current->data==val){
    tmp=current;
    current=current->next;
    free(tmp);
    return;
  }
  while(current!=NULL){
    if(current->next->data==val){
      tmp=current->next;
      current->next=current->next->next;
      free(tmp);
      if(current->next!=NULL){
        current->next->prev=current;
        return;
      }
    }
    current=current->next;
  }
}

int main(){
  Node *head=NULL;

  add_node(&head,10);
  add_node(&head,20);
  add_node(&head,40);
  insert_node(&head,20,30);
  delete_node(&head,20);
  printlist(head);

  return 0;
}
