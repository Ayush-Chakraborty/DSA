#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int n)
{
    int m = 1e9 + 7;
    long long tot = 0;
    while (n)
    {
        int msb = 0;
        for (int i = 1; i < 32; i++)
        {
            if (n & (1 << i))
                msb = i;
        }
        long long cnt = msb;
        cnt = (cnt * (1 << (msb - 1)) % m) % m;

        tot = (tot + cnt) % m;
        tot = (tot + (n - (1 << msb) + 1) % m) % m;
        n -= (1 << msb);
    }
    return tot;
}

int main()
{

    return 0;
}