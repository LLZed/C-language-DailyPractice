/*
在n*m的地图上，存在一个喷水点(x,y). 如果相邻的位置低于有水的地方，水就能流到相邻的某位置。 
已知各个地方的海拔高度，求水的最大覆盖个格子数。
遍历地图，找到所有的喷水点的位置。
1.对于每一个喷水点，以其位置为起点进行深度优先搜索。
2.在深度优先搜索的过程中，记录已经被覆盖的格子数。
3.根据深度优先搜索的结果，得到每个喷水点的最大覆盖格子数。
注意，为了避免重复搜索已经访问过的格子，我们需要使用一个布尔类型的二维数组来记录每个格子是否已经被访问过。
*/
#include <stdio.h>
#include <stdlib.h>

    int dx[] = {1, 0, -1, 0}; // x方向的增量
    int dy[] = {0, -1, 0, 1}; // y方向的增量
    int count = 0; // 最大覆盖格子数
// 判断一个位置是否在地图范围内
int isValid(int n, int m, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int n, int m, int x, int y, int ** arr, int ** visited) {
    visited[x][y] = 1; // 标记为已访问
    count++; // 更新最大覆盖格子数

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 判断相邻位置是否有效且未访问过
        if (isValid(n, m, nx, ny)&& !visited[nx][ny] && arr[nx][ny] < arr[x][y]) {
            dfs(n, m, nx, ny, arr, visited); // 继续深度优先搜索
        }
    }
}

void solution(int n, int m, int x, int y, int *arr[]) {
    int** visited = (int**)malloc(n * sizeof(int*)); // 动态分配visited数组内存
    for (int i = 0; i < n; i++) {
        visited[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            visited[i][j] = 0; // 初始化visited数组
        }
    }

    dfs(n, m, x, y, arr, visited);

    // 释放visited数组的内存
    for (int i = 0; i < n; i++) {
        free(visited[i]);
    }
    free(visited);

    printf("水的最大覆盖格子数：%d\n", count);
}

int main() {
    int temp_arr[4]; // 存放输入的四个数
    printf("输入地图行列和喷水位置坐标:\n");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &temp_arr[i]);//输入地图大小和喷水位置
    }
    int n = temp_arr[0];//地图行
    int m = temp_arr[1];//地图列
    int x = temp_arr[2];//喷水位置x坐标
    int y = temp_arr[3];//喷水位置y坐标

    int **arr = (int**)malloc(n * sizeof(int*)); // 动态分配地图数组内存
    for(int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(m * sizeof(int));
        for(int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    solution(n, m, x, y, arr);

    // 释放地图数组的内存
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
system("pause");
return 0;
}
