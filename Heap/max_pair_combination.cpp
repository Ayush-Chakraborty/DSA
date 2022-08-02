#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> solve(vector<int> &v1, vector<int> &v2)
{
    set<vector<int>, greater<vector<int>>> m;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int n = v1.size();
    m.insert({v1.back() + v2.back(), n - 1, n - 1});
    vector<int> ans(n);
    int i = 0;
    while (i < n)
    {
        auto v = *m.begin();
        ans[i] = v[0];
        i++;
        int x = v[1];
        int y = v[2];
        m.erase(m.begin());
        if (x > 0)
            m.insert({v1[x - 1] + v2[y], x - 1, y});
        if (y > 0)
            m.insert({v1[x] + v2[y - 1], x, y - 1});
    }
    return ans;
}

int main()
{

    return 0;
}