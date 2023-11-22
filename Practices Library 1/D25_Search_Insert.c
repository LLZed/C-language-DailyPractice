/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。

示例 1:
输入: nums = [1,3,5,6], target = 5
输出: 2

示例 2:
输入: nums = [1,3,5,6], target = 2
输出: 1

示例 3:
输入: nums = [1,3,5,6], target = 7
输出: 4
*/
#include <stdio.h>
#include <stdlib.h>

int flag=1;
int main(){
    int n,*arry;
    int searchInsert(int* nums, int numsSize, int target);
    printf("输入数组长度:");
    scanf("%d",&n);
    arry=(int*)malloc(n*sizeof(int));
    printf("输入%d个整型数组元素:",n);
    for(int i=0;i<n;i++)
        scanf("%d",arry+i);
    // for(int i=0;i<n;i++)
    //     printf("%d",(*arry+i));
    int target;
    printf("输入要查找的值:");
    scanf("%d",&target);
    int number=searchInsert(arry, n, target);
    if(flag == 0)
        printf("所查找元素在数组中的索引位置为%d\n",number);
    if(flag == 1)
        printf("所查找元素在数组中要插入的索引位置为%d\n",number);
    system("pause");
    return 0;
}
int searchInsert(int* nums, int numsSize, int target) {
    int left,right,mid;
    left=0;right=numsSize-1;
    // 二分法
    while(left<=right){
        mid=left+(right-left)/2;
        if(target == nums[mid]){
            flag=0;//标记元素在数组中
            return mid;
        }
        else if(target > nums[mid]){
            left=mid+1;
        }
        else if(target < nums[mid]){
            right=mid-1;
        }
    }
    return left;
}

