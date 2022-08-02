#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> ans;
void func(vector<int> &nums, int idx, vector<int> &comb, int sum, int target)
{
    if (sum == target)
        ans.push_back(comb);
    if (sum >= target || idx == nums.size())
        return;
    comb.push_back(nums[idx]);
    func(nums, idx, comb, sum + nums[idx], target);
    comb.pop_back();
    func(nums, idx + 1, comb, sum, target);
}
vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    ans.clear();
    vector<int> s;
    func(nums, 0, s, 0, target);
    return ans;
}
int main()
{

    return 0;
}