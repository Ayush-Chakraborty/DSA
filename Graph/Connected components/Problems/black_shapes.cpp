#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
void dfs(vector<string> &mat, int i, int j, vector<vector<bool>> &visited)
{
    visited[i][j] = true;

    for (int k = 0; k < 4; k++)
    {
        int r = i + dx[k];
        int c = j + dy[k];

        if (r < 0 || c < 0 || r >= n || c >= m)
            continue;

        if (mat[r][c] == 'X' && !visited[r][c])
            dfs(mat, r, c, visited);
    }
}

int black(vector<string> &mat)
{
    n = mat.size();
    m = mat[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'X' && !visited[i][j])
            {
                dfs(mat, i, j, visited);
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{

    return 0;
}