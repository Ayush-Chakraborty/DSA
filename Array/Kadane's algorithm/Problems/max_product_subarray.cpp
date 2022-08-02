#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxProduct(const vector<int> &a)
{
    ll mn = a[0];
    ll mx = a[0];
    ll ans = a[0];
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        ll t1 = mn * (ll)a[i];
        ll t2 = mx * (ll)a[i];

        mn = min({(ll)a[i], t1, t2});
        mx = max({(ll)a[i], t1, t2});
        ans = max(ans, mx);
    }
    return ans;
}

int main()
{

    return 0;
}