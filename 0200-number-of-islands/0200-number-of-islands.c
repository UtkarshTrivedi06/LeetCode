#include <stdbool.h>

void dfsIsland(char** grid, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;
    grid[i][j] = '0';
    dfsIsland(grid, i+1, j, m, n);
    dfsIsland(grid, i-1, j, m, n);
    dfsIsland(grid, i, j+1, m, n);
    dfsIsland(grid, i, j-1, m, n);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfsIsland(grid, i, j, gridSize, gridColSize[i]);
            }
        }
    }
    return count;
}
