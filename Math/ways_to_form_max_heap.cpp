#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long M = 1e9 + 7;
int num_children(int i, int n, vector<int> &cnt)
{
    if (i > n)
        return 0;
    cnt[i] = num_children(2 * i, n, cnt) + num_children(2 * i + 1, n, cnt) + 1;
    return cnt[i];
}
long long mod_inverse(int a, int p)
{
    if (p == 0)
        return 1;
    long long x = mod_inverse(a, p / 2);
    x = (x * x) % M;
    if (p % 2 == 1)
        return (x * a) % M;
    return x;
}
long long nCr(long n, long long r, vector<long long> &fact)
{
    return ((fact[n] * mod_inverse(fact[r], M - 2) % M) * mod_inverse(fact[n - r], M - 2)) % M;
}
long long func(int i, int n, vector<int> &cnt, vector<long long> &fact)
{
    int left = 2 * i;
    if (left > n)
        return 1;

    int tot = cnt[i];
    int child = cnt[2 * i];

    long long ans = 1;
    ans = (ans * nCr(tot - 1, child, fact)) % M;
    ans = (ans * func(2 * i, n, cnt, fact)) % M;
    ans = (ans * func(2 * i + 1, n, cnt, fact)) % M;
    return ans;
}
int solve(int n)
{
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (long long i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % M;
    vector<int> cnt(n + 1, 0);
    num_children(1, n, cnt);
    return func(1, n, cnt, fact);
}

int main()
{

    return 0;
}