#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxPoints(vector<int> &x, vector<int> &y)
{
    int n = x.size();
    if (n <= 1)
        return n;

    int mx = 2;
    for (int i = 0; i < n; i++)
    {
        map<double, int> cnt;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            double y1 = y[i], y2 = y[j];
            double x1 = x[i], x2 = x[j];
            double m = INT_MAX;
            if (x1 != x2)
                m = (y2 - y1) / (x2 - x1);
            cnt[m] = max(2, cnt[m] + 1);
        }
        for (auto &p : cnt)
            mx = max(mx, p.second);
    }
    return mx;
}

int main()
{

    return 0;
}