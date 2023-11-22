//有分数序列2/1,3/2,5/3,8/5，...,求这个序列前20项之和
#include <stdio.h>
#include <stdlib.h>

int main(){
    float sum=0.0;
    float a=1,b=2,t;
    int i=0;
    do{
        sum+=b/a;
        t=b;
        b=a+b;
        a=t;
        i++;
    }while(i<20);
    printf("sum=%.2f\n",sum);
    system("pause");
    return 0;
}