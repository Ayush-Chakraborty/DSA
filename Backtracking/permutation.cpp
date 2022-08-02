#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> ans;
void find_permutations(vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        find_permutations(nums, idx + 1);
        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    ans.clear();
    find_permutations(nums, 0);
    return ans;
}
int main()
{

    return 0;
}