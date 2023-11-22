/*
给定一个未排序的整数数组，找出最长连续递增子序列(子数组)的长度。
在第一行输入整数n。在第二行输入n个整数。
输出最长连续递增增量序列的长度。
比如：
输入：
5
1 3 5 4 7
输出：
最长连续递增的子序列长度为:3

每个元素本身都可以看作一个长度为 1 的上升连续子序列。
*/
#include <stdio.h>
#include <stdlib.h>

void solution(int n, int arr[]){
    int count=1,maxcount=0;//存放递增次数和最大递增次数
    for(int i=0;i<n;i++){
        if(arr[i]<arr[i+1]){
            count++;
        }
        else {
            if(count>maxcount)
                maxcount=count;
            count=1;
        }
    }
    printf("最长连续递增的子序列长度为:%d\n",maxcount);
}

int main() {
    int n;
    printf("输入序列长度:");
    scanf("%d", &n);
    
    int* arr;//定义一个整型指针
    arr = (int*)malloc(n * sizeof(int));//开辟空间，首地址存放到arr中

    printf("输入序列:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
	solution(n, arr);
    system("pause");
    return 0;
}