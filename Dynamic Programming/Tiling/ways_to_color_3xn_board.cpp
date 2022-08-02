#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int n)
{
    vector<vector<int>> triplets;
    int dp[n][4][4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (i != j && j != k)
                {
                    triplets.push_back({i, j, k});
                    dp[0][i][j][k] = 1;
                }
            }
        }
    }
    int MOD = 1e9 + 7;
    for (int i = 1; i < n; i++)
    {
        for (auto &v1 : triplets)
        {
            dp[i][v1[0]][v1[1]][v1[2]] = 0;
            for (auto &v2 : triplets)
            {
                if (v1[0] != v2[0] && v1[1] != v2[1] && v1[2] != v2[2])
                {
                    dp[i][v1[0]][v1[1]][v1[2]] += dp[i - 1][v2[0]][v2[1]][v2[2]];
                    dp[i][v1[0]][v1[1]][v1[2]] %= MOD;
                }
            }
        }
    }
    int tot = 0;
    for (auto &v : triplets)
    {
        tot += dp[n - 1][v[0]][v[1]][v[2]];
        tot %= MOD;
    }
    return tot;
}

int main()
{

    return 0;
}