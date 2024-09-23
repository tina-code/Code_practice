#include  <stdio.h>

int Binary_search(int *arr,int l,int r,int target){
    while(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==target){
            return 1;
        }
        else if(arr[mid]<target){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return 0;
}

int main(){
    int sorted_array[10]={0};
    for(int i=0;i<10;i++){
        sorted_array[i]=i;
    }
    printf("%d\n",Binary_search(sorted_array,3,7,6)); //輸出1
    printf("%d\n",Binary_search(sorted_array,3,7,1)); //輸出0
    return 0;
}