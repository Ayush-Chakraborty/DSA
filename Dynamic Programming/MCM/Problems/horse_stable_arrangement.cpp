#include <bits/stdc++.h>
using namespace std;
#define ll long long
int ***dp;
int func(string &s, int i, int j, int stables)
{
    if (j - i + 1 == stables)
        return 0;
    if (j - i + 1 < stables)
        return INT_MAX;

    if (dp[i][j][stables] != -1)
        return dp[i][j][stables];

    if (stables == 1)
    {
        int white, black;
        white = black = 0;
        for (int k = i; k <= j; k++)
        {
            if (s[k] == 'W')
                white++;
            else
                black++;
        }
        return white * black;
    }

    int mn = INT_MAX;
    int white = 0, black = 0;
    for (int k = j - 1; k >= i; k--)
    {
        if (s[k + 1] == 'W')
            white++;
        else
            black++;
        int cost = func(s, i, k, stables - 1);
        if (cost == INT_MAX)
            continue;
        mn = min(mn, cost + white * black);
    }
    return dp[i][j][stables] = mn;
}

int arrange(string a, int b)
{
    int n = a.size();
    if (b > n || b == 0)
        return -1;
    dp = new int **[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int *[n];
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = new int[b + 1];
            for (int k = 0; k <= b; k++)
                dp[i][j][k] = -1;
        }
    }

    int ans = func(a, 0, n - 1, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            delete[] dp[i][j];
        }
        delete[] dp[i];
    }
    delete[] dp;
    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{

    return 0;
}