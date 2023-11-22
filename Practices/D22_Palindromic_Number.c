/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
例如，121 是回文，而 123 不是。
 
示例 1：
输入：x = 121
输出：true
示例 2：
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3：
输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//包含这个头文件才能用bool类型

bool isPalindrome(int x){
    int i=0;
    if(x<0){
        return false;
    }
    long reversed = 0;//用long类型防止内存溢出
    int original = x;
    //直接把整数翻转过来
    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }
    return original == reversed;//对比两个整数
}
int main(){
    int x;
    printf("输入一个整数:");
    scanf("%d",&x);
    if(isPalindrome(x))//调用函数判断是否是回文数
        printf("%d是回文数\n",x);
    else
        printf("%d不是回文数\n",x);
    
    system("pause");
    return 0;
}