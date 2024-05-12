/*
对输入的字符串进行排序后输出
打开以下链接可以查看正确的代码
https://ac.nowcoder.com/acm/contest/5657#question

输入描述：
多个测试用例，每个测试用例一行。

每行通过空格隔开，有n个字符，n＜100
输出描述：
对于每组测试用例，输出一行排序过的字符串，每个字符串通过空格隔开
示例1
输入例子：
a c bb
f dddd
nowcoder
输出例子：
a bb c
dddd f
nowcoder
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//比较函数
int cmp(const void* a,const void *b){
    const char *str1=(const char*)a;
    const char *str2=(const char*)b; 
    return strcmp(str1,str2);
}

int main(){
    char str[100][10];
    int num = 0;
    while(scanf("%s",str[num++]) != EOF){
        if(getchar() == '\n'){
            qsort(str,num,sizeof(str[0]),cmp);
            for(int i = 0;i < num;i++) 
                printf("%s ",str[i]);
            printf("\n");
            num = 0; 
        }
    }
    return 0;
}