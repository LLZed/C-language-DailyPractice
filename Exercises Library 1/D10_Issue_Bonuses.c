/*
从报纸上随机取一段话，去掉所有的空格和标点，并把所有的字母替换成大写构成一个字符串。
如果这个字符串中包含字母Q或是字母B的个数大于或等于A的个数，就输出1，否则输出0。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *InputUnknownLengthString(char *str);
    void LowercaseToUppercase(char *str1,char *str2);
    int Count(char ch,char* str);

    char *str1,*str2;
    int countA=0,countQ=0,countB=0,flag=0;

    printf("请输入字符串：");
    str1=InputUnknownLengthString(str1);//输入字符串
    printf("输入的字符串为:%s\n",str1);
    
    int length=sizeof(str1);
    str2=(char *)malloc(length);//开辟和str1一样大的空间来存放转成大写之后的字符串,防止溢出
    LowercaseToUppercase(str1,str2);//小写变大写
    printf("全部字母大写后:%s\n",str2);
    free(str2); // 如果不再需要这块内存，必须释放它
    
    countA=Count('A',str2);//计算指定字符个数
    countB=Count('B',str2);
    countQ=Count('Q',str2);

    if(countA <= countB || countA <= countQ)
        flag=1;
    else 
        flag=0;
    printf("%d\n",flag);
    system("pause");
    return 0;
}
//读入未知长度字符串函数
char *InputUnknownLengthString(char *str){
    int size = 1;//大小
    int len = 0;//字符串长度
    char ch;
 
    str = (char*) malloc(size); // 分配初始内存
 
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
//小写转大写函数
void LowercaseToUppercase(char *str1,char *str2){
    int i=0,j=0;
    while(*(str1+i)!='\0'){
        if(*(str1+i) >= 'a' && *(str1+i) <='z'){
            *(str2+j)=*(str1+i)-32;
            j++;
        }
        if(*(str1+i) >= 'A' && *(str1+i) <='Z'){
            *(str2+j)=*(str1+i);
            j++;
        }
        i++;
    }
    *(str2+i)='\0';//在字符串末尾添加 '\0'，表示字符串结束
}
//计算字符串中指定字符的个数，ch为指定的字符，str是字符串地址
int Count(char ch,char* str){
    int  count=0,i=0;
    while(*(str+i)!='\0'){
        if(*(str+i)==ch)
            count++;
        i++;
    }
    return count;
}
