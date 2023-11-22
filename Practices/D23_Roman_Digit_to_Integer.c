/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。

示例 1:                 示例 2:             示例 3:             示例 4:                         示例 5:
输入: s = "III"         输入: s = "IV"      输入: s = "IX"      输入: s = "LVIII"               输入: s = "MCMXCIV"
输出: 3                 输出: 4             输出: 9             输出: 58                        输出: 1994
                                                               解释: L = 50, V= 5, III = 3.     解释: M = 1000, CM = 900, XC = 90, IV = 
提示：
1 <= s.length <= 15
s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')。
题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内。
题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int num,flag=1;        //存放转换后的整数
    char s[20];     //存放罗马字符数组
    int romanToInt(char *s);    //函数声明
    while(flag){
        printf("输入罗马字符:");       
        scanf("%s",s);
        if(strcmp(s,"END")==0){
            flag=0;
            printf("已退出\n");
        }
        else{      
            num=romanToInt(s);
            printf("罗马字符%s的整数形式为:%d (输入\"END\"退出)\n",s,num);
        }
    }
    system("pause");
    return 0;
}
int romanToInt(char *s){
    int num=0,x,y=1001,len;
    len=strlen(s);
    for(int i=0;i<len;i++){
        switch (*(s+i))
        {
            case 'I': x=1;  break;
            case 'V': x=5;  break;
            case 'X': x=10;  break;
            case 'L': x=50;  break;
            case 'C': x=100;  break;
            case 'D': x=500;  break;
            case 'M': x=1000;  break;
        }
        //如果当前罗马数的比前面的大，做减法，后面减前面
        if(x>y){
            x=x-y;          //当前大罗马数减前一个小罗马数
            num=num+x-y;    //加上差值还有减去已经加上的前一个小罗马数
            }
        //当前罗马数比前一个小，做加法
        else{
            num=num+x;  //直接相加
            y=x;        //把此时的值赋给表示前一个罗马数的y，用于与下一个罗马数比大小
        }
    }
    return num;
}
/*法二
int romanToInt(char* s) {
    int symbolValues[26];
    symbolValues['I' - 'A'] = 1;
    symbolValues['V' - 'A'] = 5;
    symbolValues['X' - 'A'] = 10;
    symbolValues['L' - 'A'] = 50;
    symbolValues['C' - 'A'] = 100;
    symbolValues['D' - 'A'] = 500;
    symbolValues['M' - 'A'] = 1000;
    int ans = 0;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        int value = symbolValues[s[i] - 'A'];
        if (i < n - 1 && value < symbolValues[s[i + 1] - 'A']) {
            ans -= value;
        } else {
            ans += value;
        }
    }
    return ans;
}

作者：力扣官方题解
链接：https://leetcode.cn/problems/roman-to-integer/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/