#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *left,*right;
}Node;

Node *create_node(int val){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->val=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void insert_binary_search_tree_recursive_ver(Node **root,int val){
    if(*root==NULL){
        *root=create_node(val);
    }
    else{
        if(val<(*root)->val){
            insert_binary_search_tree_recursive_ver(&(*root)->left,val);
        }
        else{
            insert_binary_search_tree_recursive_ver(&(*root)->right,val);
        }
    }
}

void insert_binary_search_tree_iteration_ver(Node **root,int val){
    Node *current=*root,*pre;
    if(*root==NULL){
        *root=create_node(val);
        return;
    }
    while(current!=NULL){
        pre=current;
        if(val<current->val){
            current=current->left;
        }
        else{
            current=current->right;
        }
    }
    if(val<pre->val){
        pre->left=create_node(val);
    }
    else{
        pre->right=create_node(val);
    }
}

void inorder_traversal(Node *root){
    if(root==NULL){
        return;
    }
    inorder_traversal(root->left);
    printf("%d ",root->val);
    inorder_traversal(root->right);
}

int main(){
    int arr[7]={3,5,7,4,2,1,5};
    Node *tree=NULL;
    for(int i=0;i<7;i++){
        //insert_binary_search_tree_recursive_ver(&tree,arr[i]);
        insert_binary_search_tree_iteration_ver(&tree,arr[i]);
    }
    printf("Inorder traversal of binary search tree:\n");
    inorder_traversal(tree);
    printf("\n");
    return 0;
}