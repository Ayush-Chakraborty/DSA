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
    func(nums, idx + 1, comb, sum + nums[idx], target);
    comb.pop_back();
    int i = idx;
    while (i < nums.size() && nums[i] == nums[idx])
        i++;
    func(nums, i, comb, sum, target);
}
vector<vector<int>> combinationSum2(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    ans.clear();
    vector<int> s;
    func(nums, 0, s, 0, target);
    return ans;
}
int main()
{

    return 0;
}