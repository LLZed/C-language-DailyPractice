/*
求第三个勾股数。勾股数是一组三个正整数，它们可以作为直角三角形的三条边。 
比如3 4 5就是一组勾股数。 如果给出一组勾股数其中的两个，找出余下的一个,如果余下的一个勾股数存在，则输出之。 如果不存在，则输出不存在。
注意：
在判断第三条边是否为整数时，使用了n1==(int)n1和n2==(int)n2的形式进行比较的话,但是由于浮点数精度的问题，这种比较可能不准确。
为了解决这个问题，我们可以使用以下方法：
    先将浮点数转换为整数，再将转换后的整数转回原来的浮点数；
    检查转换后的浮点数与原来的浮点数之间的差异是否接近于零。
这样可以更准确地判断浮点数是否为整数。
在代码中，我们使用了fabs()函数来计算绝对值，并设置了一个极小的容差值1e-6，用来判断浮点数与其整数化版本之间的差异是否接近于零。
这样可以更好地处理浮点数转换为整数的情况，确保输出结果的准确性。
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b;
    double n1, n2;

    printf("请输入已知的两个勾股数边长（以空格分隔）：");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("-1\n");
    } else if (a == 0 && b == 0) {
        printf("第三个边长为：0\n");
    } else {
        if (a < b) {
            int t = a;
            a = b;
            b = t;
        }

        n1 = sqrt(a * a + b * b);
        n2 = sqrt(a * a - b * b);

        int intN1 = (int)(n1 + 0.5);
        int intN2 = (int)(n2 + 0.5);

        if (fabs(n1 - intN1) < 1e-6) {
            printf("第三个边长为：%d\n", intN1);
        } else if (fabs(n2 - intN2) < 1e-6) {
            printf("第三个边长为：%d\n", intN2);
        } else {
            printf("第三个勾股数不存在！\n");
        }
    }
    system("pause");
    return 0;
}