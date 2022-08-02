#include <bits/stdc++.h>
using namespace std;
#define ll long long
int M = 1e3 + 3;
pair<int, int> dp[150][150];
pair<int, int> func(string &s, int i, int j)
{
    if (i == j)
    {
        if (s[i] == 'T')
            return {1, 0};
        else
            return {0, 1};
    }
    if (dp[i][j].first != -1)
        return dp[i][j];
    int t = 0, f = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        auto left = func(s, i, k - 1);
        auto right = func(s, k + 1, j);
        int x, y;
        x = y = 0;
        if (s[k] == '|')
        {
            x = (left.first * right.first) + (left.first * right.second) + (left.second * right.first);
            y = left.second * right.second;
        }
        else if (s[k] == '&')
        {
            x = left.first * right.first;
            y = (left.second * right.second) + (left.first * right.second) + (left.second * right.first);
        }
        else
        {
            x = left.first * right.second + left.second * right.first;
            y = (left.second * right.second) + (left.first * right.first);
        }
        x %= M;
        y %= M;
        t += x;
        f += y;
        t %= M;
        f %= M;
    }
    return dp[i][j] = {t, f};
}

int cnttrue(string a)
{
    memset(dp, -1, sizeof(dp));
    return func(a, 0, a.size() - 1).first;
}

int main()
{

    return 0;
}