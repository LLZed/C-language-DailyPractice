/*
一个n位超级素数是指一个n位正整数，它的前1位，前2位，......，前n位均为素数.
例如，733是个3位超级素数，因为7,73,733均为素数。
写一个函数输出全部的3位数超级素数。
解题思路：对一个三位数首先先判断前3位数是不是素数，然后除以10，判断前2位数是不是素数，继续除以10判断前1位数是不是素数
*/
#include <stdio.h>
#include <stdlib.h>
int isprime(int x)
{
    if (x == 0 || x == 1) return 0;
    for (int i = 2; i <= x / 2; i++)
        if (!(x % i)) return 0;
    return 1;
}
int isallprime(int x)
{
    do
    {
        if (!isprime(x)) return 0;
        x /= 10;
    }
    while (x > 0);
    return 1;
}
int main()
{
    for (int i = 111; i <= 1000; i++)
        if (isallprime(i)) 
            printf("%d\n", i);
    system("pause");
    return 0;
}