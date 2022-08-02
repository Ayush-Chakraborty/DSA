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
    func(nums, idx + 1, subset);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    ans.clear();
    vector<int> s;
    func(nums, 0, s);
    return ans;
}
int main()
{

    return 0;
}