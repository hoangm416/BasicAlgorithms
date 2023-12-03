//C++ 
#include <iostream>
#include <vector>

using namespace std;

const int N = 9;
int count = 0;

bool isValid(vector<vector<int>>& board, int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] == num) return false;
        if (board[i][col] == num) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false;
    }

    return true;
}

void solveSudoku(vector<vector<int>>& board, int row, int col)
{
    if (row == N)
    {
        count++;
        return;
    }

    if (col == N)
    {
        solveSudoku(board, row + 1, 0);
        return;
    }

    if (board[row][col] != 0)
    {
        solveSudoku(board, row, col + 1);
        return;
    }

    for (int num = 1; num <= N; num++)
    {
        if (isValid(board, row, col, num))
        {
            board[row][col] = num;
            solveSudoku(board, row, col + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    solveSudoku(board, 0, 0);

    cout << count;

    return 0;
}

