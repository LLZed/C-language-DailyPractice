/*
对输入的字符串进行排序后输出
打开以下链接可以查看正确的代码
https://ac.nowcoder.com/acm/contest/5657#question

输入描述：
输入有两行，第一行n
第二行是n个字符串，字符串之间用空格隔开
输出描述：
输出一行排序后的字符串，空格隔开，无结尾空格
示例1
输入例子：
5
c d a bb e
输出例子：
a bb c d e
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char str[n][20];
    for(int i=0; i<n ;i++)
    {
        scanf("%s",str[i]);
    }
    qsort(str, n, 20, strcmp);      //qsort函数是C语言标准库中的一个函数，可以对任意类型的数据进行快速排序
    for(int i=0;i<n;i++)
        printf("%s ",str[i]);
    return 0;
}