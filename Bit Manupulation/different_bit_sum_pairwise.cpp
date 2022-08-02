#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cntBits(vector<int> &v)
{
    vector<int> cnt(32, 0);
    for (auto x : v)
    {
        for (int i = 0; i < 32; i++)
        {
            if (x & (1 << i))
                cnt[i]++;
        }
    }
    int m = 1e9 + 7;
    long long n = v.size();
    int tot = 0;
    for (long long x : cnt)
    {
        long long c = x * (n - x);
        c %= m;
        tot = (tot + ((2ll * c) % m)) % m;
    }

    return tot;
}

int main()
{

    return 0;
}