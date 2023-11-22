/*
动态规划题
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
本题的思路与连续子数组的最大和比较相似，只是本题做的是乘法，也就需要考虑到负负得正的情况
所以，我们分别维护前一次状态最大值和最小值，当遇到负数时，说明有可能发生负负得正，那么就交换最大值和最小值.
这里不用担心最大值变小的问题，因为无非就两种情况:
1.最小值是一个正数，这个时候最大值变为最小值，乘一个负数，不会影响之前的最大值
2.最小值是一个负数，这个时候最大值变为负数，很明显负负得正，相乘变大，正好可以更新
所以不管怎么样，都不会影响我们找到最大值。
维护前一次状态的最大值和最小值的动态转移方程分别为：
tempMax = fmax(tempMax * nums[i],nums[i])
tempMin = fmin(tempMin * nums[i],nums[i])
每次都要记得更新最大值
最后返回结果即可
*/
#include <stdio.h>
#include <stdlib.h>
//使用fmax函数要包含头文件：include<math.h>
#include <math.h>   
#define N 1000
int main(){
    int n,nums[N],array[N],i;
    int maxproduct;
    int maxProduct(int* nums, int numsSize);
    printf("数组元素个数:");
    scanf("%d", &n);// 输入n的值
    printf("输入%d个数组元素:",n);
     // 输入数组元素
    for (i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }
    maxproduct=maxProduct(nums,n);

    printf("乘积最大的非空连续子数组最大乘积为%d",maxproduct);
    printf("\n");
    system("pause");
    return 0;
}
// 计算最大乘积的函数
int maxProduct(int* nums, int numsSize)
{
    int res = INT_MIN; // 初始化结果为最小值
    int tempMax = 1; // 临时变量，存储当前的最大乘积
    int tempMin = 1; // 临时变量，存储当前的最小乘积
    //遍历数组
    for(int i = 0;i<numsSize;i++)
    {
        if(nums[i] < 0) // 如果当前元素是负数
        {
             // 交换最大乘积和最小乘积
            int temp = tempMax;
            tempMax = tempMin;
            tempMin = temp;
        }
        //fmax是C语言（C99）自带的一个函数，用于比较两数大小，返回较大值
        printf("tempMax = fmax(%d * nums[%d],nums[%d])=fmax(%d * %d,%d)=",tempMax,i,i,tempMax,nums[i],nums[i]);//查看执行过程
        tempMax = fmax(tempMax * nums[i],nums[i]);//状态转移方程，更新最大乘积
        printf("%d\n",tempMax);

        printf("tempMin = fmin(%d * nums[%d],nums[%d])=fmin(%d * %d,%d)=",tempMin,i,i,tempMin,nums[i],nums[i]);//查看执行过程
        tempMin = fmin(tempMin * nums[i],nums[i]);//状态转移方程，更新最小乘积
        printf("%d\n",tempMin);

        printf("res = fmax(%d ,%d)=",res,tempMax);
        res = fmax(res,tempMax); // 更新结果
        printf("%d\n",res);
        
    }
    return res;// 返回最大乘积
}

