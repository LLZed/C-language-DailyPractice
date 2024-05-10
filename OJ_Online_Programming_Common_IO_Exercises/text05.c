/*
计算一系列数的和
打开以下链接可以查看正确的代码
https://ac.nowcoder.com/acm/contest/5657#question

输入描述：
输入的第一行包括一个正整数t(1 <= t <= 100), 表示数据组数。
接下来t行, 每行一组数据。
每行的第一个整数为整数的个数n(1 <= n <= 100)。
接下来n个正整数, 即需要求和的每个正整数。
输出描述：
每组数据输出求和的结果
示例1
输入例子：
2
4 1 2 3 4
5 1 2 3 4 5
输出例子：
10
15
*/
#include <stdio.h>

int main() {
    int t;
    int n;      //需要求和的数个数
    int a, b;
    scanf("%d",&t);
    while(t>0)
    {
        while (scanf("%d", &n) && t>0) 
        {
            b=0;
            for(int i=0; i<n ;i++)
            {
                scanf("%d",&a);
                b=a+b;
            } 
            printf("%d\n", b);
        t--;
        }
    }
    return 0;
}