#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(vector<vector<int>> &mat, vector<vector<bool>> &visited, int r, int c)
{
    int n = mat.size();
    int m = mat[0].size();

    visited[r][c] = true;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int k = 0; k < 4; k++)
    {
        int i = r + dx[k];
        int j = c + dy[k];

        if (i < 0 || j < 0 || i >= n || j >= m)
            continue;

        if (visited[i][j])
            continue;

        if (mat[i][j] >= mat[r][c])
        {
            dfs(mat, visited, i, j);
        }
    }
}

int solve(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<bool>> visited_blue(n, vector<bool>(m, false));
    vector<vector<bool>> visited_red(n, vector<bool>(m, false));

    for (int j = 0; j < m; j++)
    {
        if (!visited_blue[0][j])
            dfs(mat, visited_blue, 0, j);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited_blue[i][0])
            dfs(mat, visited_blue, i, 0);
    }

    for (int j = 0; j < m; j++)
    {
        if (!visited_red[n - 1][j])
            dfs(mat, visited_red, n - 1, j);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited_red[i][m - 1])
            dfs(mat, visited_red, i, m - 1);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited_blue[i][j] && visited_red[i][j])
                cnt++;
        }
    }

    return cnt;
}

int main()
{

    return 0;
}