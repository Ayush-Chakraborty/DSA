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
void add(int i, int x)
{
    int n = bit.size();
    for (; i < n; i += (i & (-i)))
        bit[i] += x;
}
int countInversions(vector<int> &v)
{
    map<int, vector<int>> m;
    int n = v.size();
    for (int i = 0; i < n; i++)
        m[v[i]].push_back(i);
    int cnt = 1;
    for (auto &p : m)
    {
        for (auto idx : p.second)
            v[idx] = cnt;
        cnt++;
    }
    bit.assign(n + 1, 0);
    int c = 0;
    for (auto x : v)
    {
        c += sum(n) - sum(x);
        add(x, 1);
    }
    return c;
}

int main()
{

    return 0;
}