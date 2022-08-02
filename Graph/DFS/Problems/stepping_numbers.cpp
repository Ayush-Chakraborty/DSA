#include <bits/stdc++.h>
using namespace std;
#define ll long long
set<int> s;
void dfs(int node, int mn, int mx)
{
    if (s.find(node) != s.end())
        return;

    s.insert(node);

    string s = to_string(node);
    int last_digit = node % 10;
    if (last_digit != 0)
    {
        string t = s;
        t += ('0' + last_digit - 1);
        long long x = stoll(t);
        if (x <= mx)
            dfs(x, mn, mx);
    }
    if (last_digit != 9)
    {
        string t = s;
        t += ('0' + last_digit + 1);
        long long x = stoll(t);
        if (x <= mx)
            dfs(x, mn, mx);
    }
}
vector<int> stepnum(int a, int b)
{
    vector<int> v;
    if (a == 0)
        v.push_back(0);
    s.clear();
    for (int i = 1; i <= 9; i++)
        dfs(i, a, b);
    for (int x : s)
    {
        if (x >= a)
            v.push_back(x);
    }
    return v;
}

int main()
{

    return 0;
}