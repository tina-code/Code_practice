#include <stdio.h>

int main(){
    short num[]={0x12,0x34,0x56,0x78};
    short *a=num;

    printf("%x\n",*(int*)a);                //340012,因為a存num[0]的位址，轉成int*會讀取連續4byte的資料，省略前面兩個0
    printf("%x\n",*(int*)(&num[2]));        //780056

    printf("%x\n",&num[0]);
    printf("%x\n",&num[1]);
    printf("%x\n",&num[2]);
    printf("%x\n",&num[3]);

    char *p=(char *)(&num[0]+1);            //因為num[0]的short佔2byte，所以他的位址加2byte為num[1]的位址
    printf("%x\n",*p);

    char *p1=(char *)(&num[0]);             //p1指到0x0012,會存成0x12 0x00
    printf("adress:%x,val:%x\n",p1,p1[1]);  //因為是little endian,所以記憶體位址低的地方存LSB
    printf("adress:%x,val:%x\n",p1+1,p1[0]);
    //adress:bab69240,val:0
    //adress:bab69241,val:12

    return 0;
}
