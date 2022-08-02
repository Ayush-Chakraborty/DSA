#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<vector<short>>> dp;
bool func(vector<int> &v, int idx, int cnt, int sum)
{
    if (idx > v.size())
        return false;
    if (sum == 0 && cnt == 0)
        return dp[idx][cnt][sum] = true;
    if (sum == 0 || cnt == 0)
        return dp[idx][cnt][sum] = false;

    if (dp[idx][cnt][sum] != -1)
        return dp[idx][cnt][sum];

    bool b1 = func(v, idx + 1, cnt, sum);
    bool b2 = false;
    if (v[idx] <= sum)
        b2 = func(v, idx + 1, cnt - 1, sum - v[idx]);
    return dp[idx][cnt][sum] = b1 || b2;
    return dp[idx][cnt][sum] = b1;
}
vector<vector<int>> avgset(vector<int> &v)
{
    int sum = 0;
    sort(v.begin(), v.end());
    for (auto x : v)
        sum += x;
    int n = v.size();
    dp.assign(n + 1, vector<vector<short>>(n + 1, vector<short>(sum + 1, -1)));
    int j = -1, k;
    for (int i = 1; i < n; i++)
    {
        if ((sum * i) % n)
            continue;
        int s = (sum * i) / n;
        if (func(v, 0, i, s))
        {
            j = s;
            k = i;
            break;
        }
    }
    if (j == -1)
        return {};
    vector<int> v1, v2, pos;
    int i = 0;
    while (i < n && j > 0)
    {
        if (v[i] <= j && dp[i + 1][k - 1][j - v[i]] == 1)
        {
            pos.push_back(i);
            k--;
            j -= v[i];
        }
        i++;
    }
    i = 0;
    for (int idx = 0; idx < n; idx++)
    {
        if (i < pos.size() && pos[i] == idx)
        {
            v1.push_back(v[idx]);
            i++;
        }
        else
            v2.push_back(v[idx]);
    }
    return {v1, v2};
}

int main()
{

    return 0;
}