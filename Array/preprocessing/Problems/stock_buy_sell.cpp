#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxProfit(const vector<int> &a)
{
    int n = a.size();
    if (n <= 1)
        return 0;
    int mx = 0;
    int mn = a[0];
    for (int i = 1; i < n; i++)
    {
        mx = max(mx, a[i] - mn);
        mn = min(mn, a[i]);
    }
    return mx;
}

int main()
{

    return 0;
}