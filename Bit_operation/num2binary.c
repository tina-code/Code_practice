#include <stdio.h>

void num2binary(int input){
    for(int i=sizeof(int)*8-1;i>=0;i--){
        printf("%d",(input>>i)&1);
    }
    printf("\n");
}

int main(){
    num2binary(20);
    return 0;
}