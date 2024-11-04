#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void Bubble_sort(int *p,int arrsize){  //Stable Sort(不改變順序)
    for(int i=0;i<arrsize-1;i++){
        for(int j=0;j<arrsize-1-i;j++){
            if(p[j]>p[j+1]){
                swap(p+j,p+j+1);
            }
        }
    }
}

void Insertion_sort(int *p,int arrsize){  //Stable Sort(不改變順序)
    for(int i=1;i<arrsize;i++){
        int key=p[i];
        int j=i-1;
        while(j>=0&&key<p[j]){
            p[j+1]=p[j];
            j--;
        }
        p[j+1]=key;
    }
}

void Selection_sort(int *p,int arrsize){  //Unstable sort(改變順序)
    for(int i=0;i<arrsize;i++){
        int *min=p+i;
        for(int j=i+1;j<arrsize;j++){
            if(*min>p[j]){
                min=p+j;
            }
        }
        swap(p+i,min);
    }
}

void Selection_sort_stable_ver(int *p,int arrsize){
    for(int i=0;i<arrsize;i++){
        int *min=p+i;
        for(int j=arrsize-1;j>i;j--){
            if(*min>p[j]){
                min=p+j;
            }
        }
        swap(p+i,min);
    }
}

void quicksort(int *p,int l,int r){
    if(l<r){
        int key=p[l];
        int i=l,j=r;
        while(i!=j){
            while(p[j]>key&&i<j){
                j-=1;
            }
            while(p[i]<=key&&i<j){
                i+=1;
            }
            if(i<j){
                swap(p+i,p+j);
            }
        }
        swap(p+l,p+i);
        quicksort(p,l,i-1);
        quicksort(p,i+1,r);
    }
}

int main(){
    int arrsize=20;
    int nums[arrsize];
    int *p=nums;
    for(int i=0;i<arrsize;i++){
        nums[i]=rand()%100;
    }
    printf("Before sorted!\n");
    for(int i=0;i<arrsize;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
    //Bubble_sort(nums,arrsize);
    //Insertion_sort(nums,arrsize);
    //Selection_sort(nums,arrsize);
    //Selection_sort_stable_ver(nums,arrsize);
    quicksort(nums,0,arrsize-1);
    printf("After sorted!\n");
    for(int i=0;i<arrsize;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
    return 0;
}