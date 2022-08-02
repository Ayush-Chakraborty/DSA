#include <bits/stdc++.h>
using namespace std;
#define ll long long
// a -> number of dices
// b -> number of faces
// c -> required sum
int findDiceSum(int a, int b, int c)
{
    int dp[a + 1][c + 1];
    int m = 1e9 + 7;
    for (int i = 1; i <= min(c, b); i++)
        dp[1][i] = 1;
    for (int i = min(c, b) + 1; i <= c; i++)
        dp[1][i] = 0;
    for (int i = 2; i <= a; i++)
    {
        int prefix[c + 1];
        prefix[0] = 0;
        for (int j = 1; j <= c; j++)
        {
            prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % m;
        }
        for (int j = 1; j <= c; j++)
        {
            int mn = max(j - b, 1);
            dp[i][j] = (m + prefix[j - 1] - prefix[mn - 1]) % m;
        }
    }
    return dp[a][c];
}

int main()
{

    return 0;
}