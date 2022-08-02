#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> fourSum(vector<int> &v, int target)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    int n = v.size();
    int p1, p2;
    p1 = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == p1)
            continue;
        p1 = v[i];
        p2 = INT_MAX;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] == p2)
                continue;
            p2 = v[j];
            int left = j + 1;
            int right = n - 1;
            while (right > left)
            {
                int sum = v[i] + v[j] + v[left] + v[right];
                if (sum == target)
                {
                    ans.push_back({v[i], v[j], v[left], v[right]});
                    int prev = v[left];
                    left++;
                    while (left < right && v[left] == prev)
                        left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}