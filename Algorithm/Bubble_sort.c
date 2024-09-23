#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void Bubble_sort(int *arr,int arr_size){
    for(int i=0;i<arr_size-1;i++){
        for(int j=0;j<arr_size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

int main(){
    int size;
    scanf("%d",&size);
    int array[size];
    for(int i=0;i<size;i++){
        array[i]=rand()%100;
    }
    printf("Before sorted!\n");
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    Bubble_sort(array,size);
    printf("After sorted!\n");
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}

