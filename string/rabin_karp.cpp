#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> stringMatch(string &str, string &pat)
{
    ll mod = 1e9 + 7;
    ll p = 31;
    int n = pat.size();
    int m = str.size();
    ll powers[m];
    powers[0] = 1;
    for (int i = 1; i < m; i++)
        powers[i] = (powers[i - 1] * p) % mod;

    ll hash = 0;
    for (int i = 0; i < n; i++)
    {
        ll x = ((pat[i] - 'A' + 1) * powers[i]) % mod;
        hash = (hash + x) % mod;
    }
    ll hash2 = 0;
    for (int i = 0; i < n; i++)
    {
        ll x = ((str[i] - 'A' + 1) * powers[i]) % mod;
        hash2 = (hash2 + x) % mod;
    }
    vector<int> pos;
    if (hash2 == hash)
        pos.push_back(0);
    for (int i = n; i < m; i++)
    {
        hash2 = (mod + hash2 - ((str[i - n] - 'A' + 1) * powers[i - n]) % mod) % mod;
        ll x = ((str[i] - 'A' + 1) * powers[i]) % mod;
        hash2 = (hash2 + x) % mod;
        ll y = (powers[i - n + 1] * hash) % mod;
        if (y == hash2)
            pos.push_back(i - n + 1);
    }
    return pos;
}
int main()
{

    return 0;
}