//蛇形填数
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i = 0;
    int j = 0;
    int cnt = 2;
    int a[250][250];
    a[0][0] = 1;
    while (cnt < 1000)
    {
        j++;
        while (i != -1 && j != -1)
        {
            a[i][j] = cnt++;
            if (j == 0)
                break;
            i++;
            j--;
        }
        i++;
        while (i != -1 && j != -1)
        {
            a[i][j] = cnt++;
			if (i == 0)
   				break;
			i--;
			j++;
   		}
   }
   for (int i = 0; i < 20; i++)
   {
       for (int j = 0; j < 20; j++)
       {
            printf("%4d ",a[i][j]);
       }
       printf("\n");
   }
    printf("第20行20列的数:%d\n",a[19][19]);;//找出第20行20列的数
    system("pause");
    return 0;
}