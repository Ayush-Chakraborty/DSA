#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> ans;
void func(vector<int> &nums, int idx, vector<int> &subset)
{
    if (idx == nums.size())
    {
        ans.push_back(subset);
        return;
    }
    subset.push_back(nums[idx]);
    func(nums, idx + 1, subset);
    subset.pop_back();
    int i = idx;
    while (i < nums.size() && nums[i] == nums[idx])
        i++;
    func(nums, i, subset);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    ans.clear();
    vector<int> s;
    sort(nums.begin(), nums.end());
    func(nums, 0, s);
    return ans;
}
int main()
{

    return 0;
}