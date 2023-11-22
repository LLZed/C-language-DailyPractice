/*
给你一个整数数组 nums ，请计算数组的 中心下标 。
数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

示例 1：
输入：nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
中心下标是 3 。
左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。

示例 2：
输入：nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心下标。

示例 3：
输入：nums = [2, 1, -1]
输出：0
解释：
中心下标是 0 。
左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,*arry;
    int findMiddleIndex(int* nums, int numsSize);
    printf("输入数组长度:");
    scanf("%d",&n);
    arry=(int*)malloc(n*sizeof(int));
    printf("输入%d个整型数组元素:",n);
    for(int i=0;i<n;i++)
        scanf("%d",arry+i);
    // for(int i=0;i<n;i++)
    //     printf("%d",(*arry+i));
    int number=findMiddleIndex(arry, n);
    printf("%d\n",number);
    if(number == -1)
        printf("此数组没有中心坐标!\n");
    system("pause");
    return 0;
}
/*
//法一  时间复杂度: O(n)
int findMiddleIndex(int* nums, int numsSize){
    int right=0;
    int left=0;
    //第一次循环将数组求和 记为right
    for(int i=0;i<numsSize;i++)
    {
        right+=nums[i];
    }
    //第二次循环 在每次循环中 right减去当前数组对应值 判断与left是否相等 left加上当前数组对应值
    for(int i=0;i<numsSize;i++)
    {
        right-=nums[i];
        if(left==right)
        return i;
        left+=nums[i];

    }
    return -1;
}
*/
//方法二  时间复杂度：O(n)，其中 n为数组的长度。空间复杂度：O(1)。
/*
思路
记数组的全部元素之和为 total，当遍历到第i个元素时，设其左侧元素之和为 sum，则其右侧元素之和为 total−nums[i]−sum。
左右侧元素相等即为 sum=total−nums[i]−sum 即 2×sum+nums[i]=total。
当中心索引左侧或右侧没有元素时，即为零个项相加，这在数学上称作「空和」（empty sum）。在程序设计中我们约定「空和是零」。
*/
int findMiddleIndex(int* nums, int numsSize) {
    int total = 0;
    //第一次循环将数组求和
    for (int i = 0; i < numsSize; ++i) {
        total += nums[i];
    }
    int sum = 0;//设其左侧元素之和为 sum
    //
    for (int i = 0; i < numsSize; ++i) {
        if (2 * sum + nums[i] == total) {
            return i;
        }
        sum += nums[i];
    }
    return -1;
}