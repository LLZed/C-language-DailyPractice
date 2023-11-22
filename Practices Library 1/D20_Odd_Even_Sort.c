/*
一个数组里有奇数有偶数（乱序），调整数组顺序使奇数位于偶数前面，但不改变奇数之间原来的顺序和偶数之间原来的顺序。
第一行输入整数n。 第二行输入n个整数。
输出排序后的n个整数。
示例1
输入:
4
2 3 1 23
输出:
3 1 23 2
*/

#include <stdio.h>
#include <stdlib.h>

void solution(int n,int arr[]){
	// TODO: 请在此编写代码
    int odd[n]; // 存放奇数的辅助数组
    int even[n]; // 存放偶数的辅助数组
    int oddIndex = 0; // 奇数辅助数组的索引
    int evenIndex = 0; // 偶数辅助数组的索引

    // 遍历原始数组，将奇数和偶数分别存放在辅助数组中
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            odd[oddIndex++] = arr[i];
        } 
        else {
            even[evenIndex++] = arr[i];
        }
    }

    // 将辅助数组中的元素复制回原始数组
    for (int i = 0; i < oddIndex; i++) {
        arr[i] = odd[i];
    }
    for (int i = 0; i < evenIndex; i++) {
        arr[oddIndex + i] = even[i];
    }
    
    printf("奇偶排列后的数组:");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

}

int main() {
    int n;
    printf("数组元素个数:");
    scanf("%d", &n);
    
    int* arr;
    arr = (int*)malloc(n * sizeof(int));
    printf("输入数组元素:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
	solution(n, arr);
    system("pause");
    return 0;
}