#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> bit;
int sum(int i)
{
    int tot = 0;
    for (; i > 0; i -= (i & (-i)))
        tot += bit[i];
    return tot;
}
void add(int i, int val)
{
    int n = bit.size();
    for (; i < n; i += (i & (-i)))
        bit[i] += val;
}
int find_idx(int x)
{
    int l = 1;
    int r = bit.size() - 1;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (sum(mid) >= x)
            r = mid;
        else
            l = mid + 1;
    }
    if (sum(l) == x)
        return l;
    return r;
}
vector<int> order(vector<int> &heights, vector<int> &infronts)
{
    int n = heights.size();
    map<int, int> h;
    for (int i = 0; i < n; i++)
        h[heights[i]] = infronts[i];
    vector<int> ans(n, -1);
    bit.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        add(i, 1);
    for (auto p : h)
    {
        int x = p.second;
        int i = find_idx(x + 1);
        ans[i - 1] = p.first;
        add(i, -1);
    }
    return ans;
}

int main()
{

    return 0;
}