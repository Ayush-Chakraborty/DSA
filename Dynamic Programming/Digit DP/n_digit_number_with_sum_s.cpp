#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int n, int s)
{
    int dp[n + 1][s + 1];
    int m = 1e9 + 7;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 0;
                for (int k = 0; k <= 9; k++)
                {
                    if (j >= k)
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % m;
                }
            }
        }
    }
    return (dp[n][s] - dp[n - 1][s] + m) % m;
}

int main()
{

    return 0;
}