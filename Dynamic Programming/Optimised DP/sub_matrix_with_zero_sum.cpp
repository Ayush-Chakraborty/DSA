#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(vector<vector<int>> &v)
{
    int n = v.size();
    if (n == 0)
        return 0;
    int m = v[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + v[i - 1][j - 1] - dp[i - 1][j - 1];
        }
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            map<int, int> mp;
            mp[0] = 1;
            for (int k = 1; k <= m; k++)
            {
                int sum = dp[j][k] - dp[i - 1][k];
                mp[sum]++;
            }
            for (auto p : mp)
            {
                int x = p.second - 1;
                cnt += (x * (x + 1)) / 2;
            }
        }
    }
    return cnt;
}

int main()
{

    return 0;
}