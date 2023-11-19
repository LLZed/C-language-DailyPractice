//输入未知长度的字符串

#include <stdio.h>
#include <stdlib.h>
 
int main() {
    char *str;//定义一个字符指针
    char *InputUnknownLengthString(char *str);
    str=InputUnknownLengthString(str);
    
    printf("输入的字符串为：%s\n", str); 
    system("pause");
  return 0;
}
char *InputUnknownLengthString(char *str){
    int size = 1;//大小
    int len = 0;//字符串长度
    char ch;
 
    str = (char*) malloc(size); // 分配初始内存
    printf("请输入字符串：");
 
    while ((ch = getchar()) != '\n') { // 逐个读取字符，直到读取换行符为止
        if (len >= size) { // 如果当前字符串长度超过了已分配内存的大小，则重新分配更多的内存
            size *= 2;
            str = (char*) realloc(str, size);//对已开辟的区域重新分配
        }
        *(str + len) = ch; // 将读取的字符存储到字符串中
        len++;
    }
 
    *(str + len) = '\0'; // 在字符串末尾添加 '\0'，表示字符串结束
    return str;
    free(str); // 如果不再需要这块内存，必须释放它
}