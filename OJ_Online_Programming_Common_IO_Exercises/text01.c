/*
输入描述：
输入包括两个正整数a,b(1 <= a, b <= 1000),输入数据包括多组。
输出描述：
输出a+b的结果
示例1
输入例子：
1 5
10 20
输出例子：
6
30*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF) 
    { 
        printf("%d\n", a + b);
    }
    system("pause"); 
    return 0;
    
}