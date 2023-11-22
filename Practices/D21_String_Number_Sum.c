/*
给定两个字符串形式的非负整数 num1 和 num2 ，计算它们的和。 
注意： - num1 和 num2 的长度都小于 5100. - num1 和 num2 都只包含数字 0-9.
- num1 和 num2 都不包含任何前导零。 
- 你不能使用任何內建 BigInteger 库，也不能直接将输入的字符串转换为整数形式。
示例1
输入:
234 222
输出:
456

【解题思路】
创建一个数组result，用于存储相加结果。
从num1和num2的末尾开始遍历，同时用两个指针i和j分别指向num1和num2的末尾。
将num1[i]和num2[j]转换为对应的数字，分别记为n1和n2。
将n1和n2相加，并加上之前的进位carry（初始值为0），得到当前位的和sum。
将sum对10取余，得到当前位的值，并将其存入result数组中。
将sum除以10，得到进位carry。
将指针i和j分别向前移动一位，继续下一位的相加。
当两个指针都移动到字符串的开头时，相加结束。
如果最后的进位carry不为0，将其加入result数组中。
将result数组翻转，并转换为字符串形式的结果。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxSize = len1 > len2 ? len1 : len2;
    int* result = (int*)malloc((maxSize + 1) * sizeof(int)); // 存储相加结果
    int i = len1 - 1, j = len2 - 1, k = 0; // i和j分别指向num1和num2的末尾，k用于指向result数组
    int carry = 0; // 进位

    while (i >= 0 || j >= 0) {
        int n1 = i >= 0 ? num1[i] - '0' : 0; // 将num1[i]转换为对应的数字
        int n2 = j >= 0 ? num2[j] - '0' : 0; // 将num2[j]转换为对应的数字
        int sum = n1 + n2 + carry; // 当前位的和

        result[k] = sum % 10; // 当前位的值
        carry = sum / 10; // 进位

        i--;
        j--;
        k++;
    }

    if (carry != 0) {
        result[k] = carry; // 最后的进位
        k++;
    }

    char* res = (char*)malloc((k + 1) * sizeof(char)); // 存储字符串形式的结果
    int index = 0;

    for (int i = k - 1; i >= 0; i--) {
        res[index] = result[i] + '0'; // 将数字转换为字符
        index++;
    }

    res[index] = '\0'; // 字符串结束符

    free(result);

    return res;
}

int main() {
    // char num1[5100];
    // char num2[5100]; 
    // printf("请输入第一个字符串：");
    // scanf("%s", num1);  
    // printf("请输入第二个字符串：");
    // scanf("%s", num2);

    int len1,len2,n1,n2;
    printf("数组1元素个数:");
    scanf("%d", &len1);
    n1=len1+1;
    char* num1=(char*)malloc(n1 * sizeof(char));
    printf("输入数组1元素(数字):");
    scanf("%s", num1);

    printf("数组2元素个数:");
    scanf("%d", &len2);
    n2=len2+1;
    char* num2=(char*)malloc(n2 * sizeof(char));
    printf("输入数组2元素(数字):");
    scanf("%s", num2);
printf("%s+", num1);
printf("%s=", num2);

    char* res = addStrings(num1, num2);
    printf("%s\n", res);
    free(res);
    system("pause");
    return 0;
}
