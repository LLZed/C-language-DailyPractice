/*
从 1 到 N 的所有不同整数的异或和是多少
实例：
输入：5
输出：1
提示：1 ^ 2 ^ 3 ^ 4 ^ 5 = 3 ^ 3 ^ 4 ^ 5 = 4 ^ 5 = 1
*/
#include <stdio.h>
#include <stdlib.h>

void solution(int N){
 
	// TODO: 请在此编写代码
    int num=1;
    for(int i=2;i<=N;i++){
        num=num ^ i;
    }
    printf("%d",num);
}

int main() {
    int N;
    printf("输入整数(N>1):");
    scanf("%d", &N);
    printf("从 1 到 %d 的所有不同整数的异或和是 ",N);
	solution(N);
    printf("\n");
    system("pause");
    return 0;
}