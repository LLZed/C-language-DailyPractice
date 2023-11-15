/*
小林和小树兄弟俩相约存零钱。眼看到年底了，兄弟俩决定算算一共存了多少钱，请帮他们算出来。
输入：
两行，第一行三个整数分别对应元、角、分，表示小林存的零钱数；
第二行三个整数分别对应元、角、分，表示小树存的零钱数。

输出：
两人存的钱数（单位：元，保留2位小数)
样例输入：
30 5 5
45 7 4
样例输出：
76.29
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int y1,j1,f1,y2,j2,f2;
	int y,j,f;
	int shiftj = 0;//计算分进位
	int shifty = 0;//计算角进位
	float sum ;
    printf("输入元 角 分对应数目:\n");
	scanf("%d %d %d",&y1,&j1,&f1);
	scanf("%d %d %d",&y2,&j2,&f2);
	f = f1 + f2;
	if(f>=10)
	{
		f = f-10;
		shiftj = 1;//分满10分进位1角
	}
	j = j1 + j2 + shiftj;
	if(j>=10){
        j=j-10;
        shifty=1;//角满10角进位1元
    }
	y = y1 + y2 + shifty;
	sum = y + j/10.0 + f/100.0;
	printf("零钱总数目为：%.2f\n",sum);
    system("pause");
	return 0;
}