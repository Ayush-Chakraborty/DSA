#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<vector<vector<int>>> dp;
int n, m;
int func(vector<string> &board, int i, int j, int dir)
{
    int x = i + dx[dir];
    int y = j + dy[dir];

    if (dp[i][j][dir] != -1)
        return dp[i][j][dir];

    if (x < 0 || y < 0 || x >= n || y >= m)
        return dp[i][j][dir] = 0;

    return dp[i][j][dir] = (board[x][y] == '1') || func(board, x, y, dir);
}
vector<vector<int>> queenAttack(vector<string> &board)
{
    n = board.size();
    m = board[0].size();

    dp.assign(n, vector<vector<int>>(m, vector<int>(8, -1)));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                ans[i][j] += func(board, i, j, k);
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}