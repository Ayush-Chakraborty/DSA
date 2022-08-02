#include <bits/stdc++.h>
using namespace std;
#define ll long long
int minSumPath(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = INT_MAX;
            else if (i == 1 && j == 1)
                dp[i][j] = a[0][0];
            else
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i - 1][j - 1];
        }
    }
    return dp[n][m];
}

int main()
{

    return 0;
}