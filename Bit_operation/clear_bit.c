#include <stdio.h>
#define clear_nth_bit_1(a,n) ((a)&=~(1<<n))

int clear_nth_bit(int a,int n){
    return a & ~(1<<n);
}

int main(){
    int x=15;  //15=1111_2   clear 3rd bit->0111_2=7
    int res=clear_nth_bit(x,3);
    printf("%d by function\n",res);
    printf("%d by define\n",clear_nth_bit_1(x,3));
}