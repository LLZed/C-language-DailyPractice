/*
动态规划题
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。
示例1:
输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
【解题思路】
利用动态规划的思想，对于数组每一位的数字，只有两种情况：
将此元素与之前的子数组组合在一起，形成一个新的子数组
此元素自己单独作为一个子数组或者子数组的开始
我们只需要在这两种情况里面选择最大的那个保存为截止到当前位置的最大值
然后不停的更新最大值
最后返回结果即可
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//使用fmax函数要包含math头文件，fmax是C语言（C99）自带的一个函数，用于比较两数大小，返回较大值
#define N 1000

//定义函数，输入为整数数组和数组长度
int maxSubArray(int* nums, int numsSize)
{
    int* dp = (int*)malloc(sizeof(int) * numsSize);//开辟存储空间
    dp[0] = nums[0];//初始化dp[0]
    int max = dp[0]; //初始化max
     //遍历整个数组
    for(int i = 1;i<numsSize;i++)
    {
        dp[i] = fmax(dp[i -1] + nums[i],nums[i]);//状态转移方程
        printf("dp[%d]=fmax(dp[%d] + nums[%d],nums[%d])=%d ",i,i-1,i,i,dp[i]);//查看执行过程
        max = fmax(dp[i],max);//更新max
        printf("max=%d\n",max);//查看执行过程
    }
    return max;//返回最大子序和
}
int main(){
    int nums[N],numsSize,i;
    int sum; //存放最终的结果
    printf("数组元素个数:");
    scanf("%d",&numsSize);
    printf("输入%d个数组元素:",numsSize);
    for(i=0;i<numsSize;i++)
        scanf("%d",&nums[i]);
    sum=maxSubArray(nums,numsSize);
    printf("最大子序和为%d\n",sum);
    system("pause");
    return 0;
}