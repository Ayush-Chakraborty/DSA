#include <bits/stdc++.h>
using namespace std;
#define ll long long
int M = 100;
int dp[100][100];
int func(vector<int> &v, int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int n = j - i + 1;
    int prefix_sum[n];
    int suffix_sum[n];

    prefix_sum[0] = v[i];
    for (int k = 1; k < n; k++)
        prefix_sum[k] = (prefix_sum[k - 1] + v[i + k]) % M;

    suffix_sum[n - 1] = v[j];
    for (int k = n - 2; k >= 0; k--)
        suffix_sum[k] = (suffix_sum[k + 1] + v[i + k]) % M;

    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int x = prefix_sum[k - i];
        int y = suffix_sum[k + 1 - i];
        int cost = func(v, i, k) + func(v, k + 1, j) + (x * y);
        mn = min(mn, cost);
    }

    return dp[i][j] = mn;
}

int minSmoke(vector<int> &a)
{
    memset(dp, -1, sizeof(dp));
    return func(a, 0, a.size() - 1);
}

int main()
{

    return 0;
}