#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=*a;
}

void Insertion_sort(int *arr,int n){ //比較不需要一直swap
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    Insertion_sort(array,size);
    printf("After sorted!\n");
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}