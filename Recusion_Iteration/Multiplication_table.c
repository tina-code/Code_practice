#include <stdio.h>

void Recursion(int i,int j){
    if(i>9){
        return;
    }
    else if(j>9){
        printf("\n");
        Recursion(i+1,1);
    }
    else{
        printf("%d ",i*j);
        Recursion(i,j+1);
    }
}

void Iteration(int n){
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            printf("%d ",i*j);
        }
        printf("\n");
    }
}

int main(){
    printf("By Recursion:\n");
    Recursion(1,1);
    printf("By Iteration:\n");
    Iteration(9);
    return 0;
}