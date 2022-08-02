#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> ans;
void perms(vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    unordered_set<int> s;
    for (int i = idx; i < nums.size(); i++)
    {
        if (s.find(nums[i]) != s.end())
            continue;
        s.insert(nums[i]);
        swap(nums[idx], nums[i]);
        perms(nums, idx + 1);
        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int> &nums)
{
    ans.clear();
    perms(nums, 0);
    return ans;
}
int main()
{

    return 0;
}