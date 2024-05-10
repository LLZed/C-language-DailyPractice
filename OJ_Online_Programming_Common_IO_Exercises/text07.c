/*
计算一系列数的和
打开以下链接可以查看正确的代码

https://ac.nowcoder.com/acm/contest/5657#question

每行不定有n个整数，空格隔开。(1 <= n <= 100)。
输出描述：
每组数据输出求和的结果
示例1
输入例子：
1 2 3
4 5
0 0 0 0 0
输出例子：
6
9
*/
#include <stdio.h>

int main() {
    int a, b = 0;
    while (scanf("%d", &a) != EOF ) {
        b = a + b;
        if (getchar() == '\n')      //如果检测到换行
        {
            printf("%d\n", b);
            b=0;
        }
    }
    return 0;
}