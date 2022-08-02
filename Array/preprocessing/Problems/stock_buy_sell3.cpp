#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maxProfit(const vector<int> &a)
{
    int n = a.size();
    if (n <= 1)
        return 0;
    int prefix[n];
    int suffix[n];
    int mn = a[0];
    prefix[0] = 0;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], a[i] - mn);
        mn = min(mn, a[i]);
    }

    suffix[n - 1] = 0;
    int mx = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], mx - a[i]);
        mx = max(mx, a[i]);
    }
    int sell = prefix[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        sell = max(sell, prefix[i - 1] + suffix[i]);
    }
    return sell;
}

int main()
{

    return 0;
}