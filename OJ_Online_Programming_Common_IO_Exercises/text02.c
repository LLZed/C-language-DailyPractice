/*
输入描述：
输入第一行包括一个数据组数t(1 <= t <= 100)
接下来每行包括两个正整数a,b(1 <= a, b <= 1000)
输出描述：
输出a+b的结果
示例1
输入例子：
2
1 5
10 20
输出例子：
6
30
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int a, b;
    scanf("%d",&n); 
    for(int i=0;i < n;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n", a + b);
    }
    system("pause");
    return 0;
}