#include <bits/stdc++.h>
using namespace std;
#define ll long long
int fibsum(int n)
{
    if (n == 0)
        return 0;

    if (n <= 2)
        return 1;

    set<int> s;
    s.insert(1);
    s.insert(2);

    int p1, p2;
    p1 = 1;
    p2 = 2;

    while (p2 < n)
    {
        int t = p1 + p2;
        s.insert(t);
        p1 = p2;
        p2 = t;
    }

    if (p2 == n)
        return 1;

    int cnt = 0;
    while (n)
    {
        auto it = s.upper_bound(n);
        it--;
        n -= (*it);
        cnt++;
    }
    return cnt;
}

int main()
{

    return 0;
}