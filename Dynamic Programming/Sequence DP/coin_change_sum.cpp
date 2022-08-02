#include <bits/stdc++.h>
using namespace std;
#define ll long long
int coinchange2(vector<int> &a, int b)
{
    int n = a.size();
    int dp[2][b + 1];
    int m = 1000007;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            if (j == 0)
                dp[1][j] = 1;
            else if (i == 0)
                dp[1][j] = 0;
            else
            {
                if (a[i - 1] <= j)
                    dp[1][j] = (dp[0][j] + dp[1][j - a[i - 1]]) % m;
                else
                    dp[1][j] = dp[0][j];
            }
        }
        for (int j = 0; j <= b; j++)
            dp[0][j] = dp[1][j];
    }
    return dp[0][b];
}

int main()
{

    return 0;
}