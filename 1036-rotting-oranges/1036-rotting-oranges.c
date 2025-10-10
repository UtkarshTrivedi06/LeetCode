#include <stdbool.h>
#include <stdlib.h>

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int fresh = 0, minutes = 0;
    int queue[m*n][2];
    int front = 0, rear = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 2)
                queue[rear][0] = i, queue[rear++][1] = j;
            else if (grid[i][j] == 1)
                fresh++;

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (front < rear && fresh > 0) {
        int size = rear - front;
        for (int k = 0; k < size; k++) {
            int x = queue[front][0], y = queue[front++][1];
            for (int d = 0; d < 4; d++) {
                int nx = x + dirs[d][0], ny = y + dirs[d][1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear][0] = nx; queue[rear++][1] = ny;
                    fresh--;
                }
            }
        }
        minutes++;
    }
    return fresh == 0 ? minutes : -1;
}
