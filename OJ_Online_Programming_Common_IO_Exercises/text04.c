/*
计算一系列数的和
打开以下链接可以查看正确的代码
https://ac.nowcoder.com/acm/contest/5657#question

输入描述：
输入数据包括多组。
每组数据一行,每行的第一个整数为整数的个数n(1 <= n <= 100), n为0的时候结束输入。
接下来n个正整数,即需要求和的每个正整数。
输出描述：
每组数据输出求和的结果
示例1
输入例子：
4 1 2 3 4
5 1 2 3 4 5
0
输出例子：
10
15
*/
#include <stdio.h>

int main() {
    int n;
    int a, b;
    while (scanf("%d", &n) && (n != 0)) 
    {
        b=0;
        for(int i=0; i<n ;i++)
        {
            scanf("%d",&a);
            b=a+b;
        } 
        printf("%d\n", b);
    }
    return 0;
}