#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

void dfs(vector<vector<char>> &board, int r, int c)
{
    board[r][c] = '*';

    for (int k = 0; k < 4; k++)
    {
        int i = r + dx[k];
        int j = c + dy[k];

        if (i < 0 || j < 0 || i >= n || j >= m)
            continue;
        if (board[i][j] == 'O')
            dfs(board, i, j);
    }
}
void solve(vector<vector<char>> &board)
{
    n = board.size();
    m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        if (board[i][0] == 'O')
            dfs(board, i, 0);
    }
    for (int i = 0; i < m; i++)
    {
        if (board[0][i] == 'O')
            dfs(board, 0, i);
    }
    for (int i = 0; i < n; i++)
    {
        if (board[i][m - 1] == 'O')
            dfs(board, i, m - 1);
    }
    for (int i = 0; i < m; i++)
    {
        if (board[n - 1][i] == 'O')
            dfs(board, n - 1, i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            if (board[i][j] == '*')
                board[i][j] = 'O';
        }
    }
}
int main()
{

    return 0;
}