/*
整个20世纪（1901年1月1日至2000年12月31日之间），一共有多少个星期一？
以下程序实现了这一功能，请你补全以下空白处内容：
解题思路：
1901.01.01是星期二。
2001.01.01是星期一。
判断1901年1月1日到2000年12月31的每一天是星期几，如果是星期一则统计的个数+1。
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year, day, dayrun = 0, dayping = 0, sumday = 0;
    int count = 0;//存放是星期一的天数
    //计算1901到2000年间共有多少天
    for (year = 1901; year <= 2000; year++)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            dayrun += 366;//闰年总天数
        }
        else
        {
            dayping += 365;//平年总天数
        }
    }
    sumday = dayrun + dayping;//天数总和

    //count=sumday/7;//因为知道了1901.01.01是星期二，所以直接用这一句求除数也能得到结果
    for(day=2;day<=sumday-7;day+=7)//因为1901.01.01是星期二，所以day=2，每次一周为递加单位，除了第一周每周都有周一，所以sumday-7
        count++;

    printf("共有%d个星期一\n", count);
    system("pause");
    return 0;
}
/*
//另一种思路
int main(void){
    int months[]={0,31,28,31,30,31,30,31,31,30,31,30,31},year,month,day,count = 0,week = 1; //1.1是周一
    for(year = 1901;year <= 2000;year++){
        // 判断是否闰年
        if(year % 400 == 0 or (year % 4 == 0 and year % 100 != 0))    
            months[2] = 29;
        else    
            months[2] = 28;
        
        for(month = 1;month <= 12;month++){
            for(day = 1;day <= months[month];day++){
                week++;
                if(week  >  7){
                    week = 1;    
                    count++;
                }
            }
        }
    } 
    printf("%d",cnt);        //结果是 5217 
    system("pause");   
    return 0;
}
*/
