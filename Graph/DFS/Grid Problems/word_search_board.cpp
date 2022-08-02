#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
bool dfs(vector<string> &mat, string &str, int r, int c, int idx)
{
    if (idx == str.size())
        return true;

    for (int k = 0; k < 4; k++)
    {
        int i = r + dx[k];
        int j = c + dy[k];

        if (i < 0 || j < 0 || i >= n || j >= m)
            continue;
        if (mat[i][j] == str[idx] && dfs(mat, str, i, j, idx + 1))
            return true;
    }
    return false;
}
int exist(vector<string> &mat, string s)
{
    if (s.size() == 0)
        return 1;

    n = mat.size();
    m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == s[0] && dfs(mat, s, i, j, 1))
                return 1;
        }
    }
    return 0;
}

int main()
{

    return 0;
}