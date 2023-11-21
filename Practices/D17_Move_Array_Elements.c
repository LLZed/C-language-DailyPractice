/*
将一维数组中的元素循环左移 k 个位置.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 10000
int main()
{
    int k, a[N], b[N], n, t, w, i;
    printf("数组元素个数:");
    scanf("%d", &n);// 输入n的值
    printf("输入%d个数组元素:",n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]); // 输入数组a的元素
    printf("移动的位置:");
    scanf("%d", &k);// 输入k的值
/*
用k%n的目的是可能存在比如我有5个数字，但我移动10位，相当于循环了两次并没有进行移动。
而k=11时，理论上是移动11位，实际上循环2次后只需要移动1位就符合条件了。
*/
    for (i = 0; i < k % n; i++)
        b[i] = a[i]; // 将数组a的前k%n个元素赋值给数组b
    for (i = 0; i < n; i++)
    {
        if(i< n - k % n)
            a[i]=a[i + k % n];   // 将数组a的第i个元素赋值为数组a中第i+k%n个元素
        else
            a[i]=b[i - n + k % n];   // 将数组b的元素赋值给数组a的后k%n个位置
    }
    printf("移动后的数组:\n");
//    for (i = 0; i < n; i++)
//        printf("%d\n", a[i]); // 输出数组a的元素
    for (i = 0; i < n; i++)
        printf("%d", a[i]); // 输出数组a的元素
    
    printf("\n");
    system("pause");
    return 0;
}
