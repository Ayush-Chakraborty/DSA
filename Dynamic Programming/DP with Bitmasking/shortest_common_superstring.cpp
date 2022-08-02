#include <bits/stdc++.h>
using namespace std;
#define ll long long
int get_overlapping_length(string &a, string &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int mx = 0;
    for (int i = n1 - 1; i >= 0; i--)
    {
        int j = i;
        int k = 0;
        int cnt = 0;
        while (j < n1 && k < n2 && a[j] == b[k])
        {
            cnt++;
            j++;
            k++;
        }
        if (j == n1)
            mx = max(mx, cnt);
    }
    return mx;
}
int solve(vector<string> &a)
{
    int n = a.size();
    int overlap[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            overlap[i][j] = get_overlapping_length(a[i], a[j]);
        }
    }
    int dp[n][(1 << n)];
    for (int mask = 1; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!(mask & (1 << i)))
                continue;
            int mask2 = (mask ^ (1 << i));
            if (mask2 == 0)
                dp[i][mask] = a[i].size();
            else
            {
                dp[i][mask] = INT_MAX;
                for (int j = 0; j < n; j++)
                {
                    if (mask2 & (1 << j))
                        dp[i][mask] = min(dp[i][mask], dp[j][mask2] + (int)a[i].size() - overlap[i][j]);
                }
            }
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, dp[i][(1 << n) - 1]);
    }
    return mn;
}

int main()
{

    return 0;
}