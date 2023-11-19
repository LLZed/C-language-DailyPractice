/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
 
示例 1：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    int binary_search(int *nums, int len, int target);
    bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize, int target);

    int target;
    // 创建一个3x4的二维矩阵
	int row = 3;    //矩阵3行,初始化 row 为矩阵的最后一行的索引（matrix.length - 1）
	int col = 4;    //矩阵4列,初始化 col 为矩阵的最后一列的索引（4）
	int **mat = malloc(row * sizeof(int *));    //开辟空间存放二维矩阵的首地址，开辟了row个int*指针大小的空间，用于存放每行矩阵首地址
    
	mat[0] = malloc(col * sizeof(int));     //开辟col个int类型大小的空间，开辟的空间首地址存放到mat[0]中
	mat[0][0] = 1;
	mat[0][1] = 3;
	mat[0][2] = 5;
	mat[0][3] = 7;
	mat[1] = malloc(col * sizeof(int));     //开辟col个int类型大小的空间，开辟的空间首地址存放到mat[1]中
	mat[1][0] = 10;
	mat[1][1] = 11;
	mat[1][2] = 16;
	mat[1][3] = 20;
	mat[2] = malloc(col * sizeof(int));     //开辟col个int类型大小的空间，开辟的空间首地址存放到mat[2]中
	mat[2][0] = 23;
	mat[2][1] = 30;
	mat[2][2] = 34;
	mat[2][3] = 50;
    printf("输入要查找的数：");
    scanf("%d",&target);
	printf("%s\n", searchMatrix(mat, row, col, target) ? "true" : "false");//调用函数，在二维矩阵中查找目标值，并打印结果
    system("pause");// 暂停程序，防止命令行窗口一闪而过// 暂停程序，防止命令行窗口一闪而过
	return 0;
}

// 二分法查找函数，用于在一维数组中搜索目标值
int binary_search(int *nums, int len, int target)//定义内部函数，搜索矩阵元素，参数是nums指针，列大小，要寻找的元素
{
	int low = -1;
	int high = len;
	while (low + 1 < high)
	{
		int mid = low + (high - low) / 2;//二分法查找元素
		if (target > nums[mid])
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
	if(high == len || nums[high] != target) //如果high等于列的长度或者high位置上的元素不是所找元素
    {
        return -high-1 ;    //返回
    }
	else
	{
		return high;    //否则返回所找元素的当前位置
	}
}

// 判断目标值是否在二维矩阵中存在的函数
bool searchMatrix(int **matrix, int matrixRowSize, int matrixColSize, int target)//形参是二维二维整数指针，行数，列数，要查找的元素
{
    //判断矩阵是否为空矩阵
	if (matrixRowSize == 0 || matrixColSize == 0)
	{
		return false;   //如果行列大小都是0，返回false
	}
    //判断目标值是否在矩阵范围之外
	if (target < matrix[0][0] || target > matrix[matrixRowSize - 1][matrixColSize - 1])
	{
		return false;   //如果查找的元素不在矩阵内，返回false
	}

    // 找到目标值在第一列的位置
	int row = 0;    //定位0列
	int *nums = NULL;   //定义一个int型空指针,创建一个指针 nums，用来存储矩阵第一列的元素。 
	if (matrixRowSize > 0)  //当列大小>0时
	{
		nums = malloc(matrixRowSize * sizeof(int));     //nums指针指向一个新开辟的大小是matrixRowSize * sizeof(int)的空间
		for (row = 0; row < matrixRowSize; row++)   //遍历一行的所有元素
		{
			nums[row] = matrix[row][0];//赋值
		}

        //使用 binary_search 函数在 nums 数组中查找目标值的位置。
		row = binary_search(nums, matrixRowSize, target);   //调用函数，参数是nums指针，列大小，要寻找的元素
		if (row >= 0)   //如果返回的row>=0，说明所找元素在矩阵里
		{
			return true;
		}
        //如果目标值在 nums 数组中未找到，则将返回的位置取反，并减去1作为 row 的索引值，即目标值应该插入的行位置。
		else    //
		{
			row = -row - 1;
            //如果 row 的值为0，则说明目标值小于矩阵最小值，直接返回 false
			if (row == 0)
			{
				return false;
			}
            //将 row 的值减去1，作为目标值应该在的行位置。
			else
			{
				row--;
			}
		}
	}

    // 在目标行中查找目标值
	int col = binary_search(matrix[row], matrixColSize, target);//如果在该行中找到目标值的列位置，则返回 true
	return col >= 0;
}
