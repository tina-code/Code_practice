#include <stdio.h>
#define set_nth_bit_1(a,n) ((a)|=(1<<n))

int set_nth_bit(int a,int n){
    return a | (1<<n);
}

int main(){
    int x=9;  //9=1001_2   set 2nd bit->1101_2=13
    int res=set_nth_bit(x,2);
    printf("%d by function\n",res);
    printf("%d by define\n",set_nth_bit_1(x,2));
}