#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ll long long
vector<vector<ll>> dp;
vector<vector<int>> dp2;
vector<int> ans;
ll func(vector<ll> &cuts, int i, int j)
{
    ll mn = LLONG_MAX;
    int n = cuts.size();
    if (j - i <= 1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    for (int k = i + 1; k < j; k++)
    {
        if (func(cuts, i, k) + func(cuts, k, j) < mn)
        {
            mn = func(cuts, i, k) + func(cuts, k, j);
            dp2[i][j] = k;
        }
    }
    return dp[i][j] = mn + cuts[j] - cuts[i];
}
void dfs(vector<ll> &cuts, int i, int j)
{
    if (j < i || dp2[i][j] == -1)
        return;
    ans.push_back(cuts[dp2[i][j]]);
    dfs(cuts, i, dp2[i][j]);
    dfs(cuts, dp2[i][j], j);
}
vector<int> rodCut(int len, vector<int> &cuts)
{
    vector<ll> v = {0};
    for (auto x : cuts)
        v.push_back(x);
    v.push_back(len);
    int n = v.size();
    dp.assign(n, vector<ll>(n, -1));
    dp2.assign(n, vector<int>(n, -1));
    ans.clear();
    func(v, 0, n - 1);
    dfs(v, 0, n - 1);
    return ans;
}

int main()
{

    return 0;
}