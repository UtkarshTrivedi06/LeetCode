#include <stdbool.h>

void dfsMark(char** board, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;
    board[i][j] = 'E';
    dfsMark(board, i+1, j, m, n);
    dfsMark(board, i-1, j, m, n);
    dfsMark(board, i, j+1, m, n);
    dfsMark(board, i, j-1, m, n);
}

void solve(char** board, int boardSize, int* boardColSize) {
    int m = boardSize, n = boardColSize[0];
    for (int i = 0; i < m; i++) {
        dfsMark(board, i, 0, m, n);
        dfsMark(board, i, n-1, m, n);
    }
    for (int j = 0; j < n; j++) {
        dfsMark(board, 0, j, m, n);
        dfsMark(board, m-1, j, m, n);
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == 'E') board[i][j] = 'O';
}
