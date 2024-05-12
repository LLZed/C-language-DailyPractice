/*
对输入的字符串进行排序后输出
打开以下链接可以查看正确的代码
https://ac.nowcoder.com/acm/contest/5657#question
输入描述：
多个测试用例，每个测试用例一行。
每行通过,隔开，有n个字符，n＜100
输出描述：
对于每组用例输出一行排序后的字符串，用','隔开，无结尾空格
示例1
输入例子：
a,c,bb
f,dddd
nowcoder
输出例子：
a,bb,c
dddd,f
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

int main(void)
{
    char str_temp[100] = {0};
    char str[100][100] = {0};
    int count = 0;
     
    while(scanf("%s",str_temp)!=EOF)
    {
        char *t = strtok(str_temp,",");    
        while(t!=NULL)
        {
            strcpy(str[count++],t);
            t = strtok(NULL,",");
        }
        qsort(str,count,sizeof(str[0]),cmp);
         
        for(int i = 0; i<count; i++)
        {
            if(i<(count-1))printf("%s,",str[i]);
            else printf("%s\n",str[i]);
        }
        count = 0;
    }
     
    return 0;
}
/*
strtok函数功能：切割字符串，将str切分成一个个子串
strtok的函数原型：
char* strtok (char* str, const char* delimiters);
str：待分隔的字符串；
delimiters：分隔字符串。
*/