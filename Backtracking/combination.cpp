#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> ans;
void func(int start, int end, int k, vector<int> &comb)
{
    if (k == 0)
    {
        ans.push_back(comb);
        return;
    }
    for (int i = start; i <= end - k + 1; i++)
    {
        comb.push_back(i);
        func(i + 1, end, k - 1, comb);
        comb.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    ans.clear();
    vector<int> s;
    func(1, n, k, s);
    return ans;
}
int main()
{

    return 0;
}