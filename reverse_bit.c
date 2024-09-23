#include <stdio.h>

unsigned int bit_reverse(unsigned int input){
    unsigned int ans=0;
    int bit_num=sizeof(int)*8;
    for(int i=0;i<bit_num;i++){
        int bit=(input>>i)&1;
        ans|=bit<<(bit-i-1);
    }
    return ans;
}

int main(){
    printf("%X", bit_reverse(0xE15DC543)); 
    // Input:  E15DC543(HEX) => 1110_0001_0101_1101_1100_0101_0100_0011(BIN)
    // Output: C2A3BA87(HEX) => 1100_0010_1010_0011_1011_1010_1000_0111(BIN)
    return 0;
}