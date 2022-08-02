#include <bits/stdc++.h>
using namespace std;
#define ll long long
class NumArray
{
public:
    int n;
    vector<int> tree;
    NumArray(vector<int> &nums)
    {
        int sz = nums.size();
        while (__builtin_popcount(sz) != 1)
        {
            sz++;
            nums.push_back(0);
        }
        n = sz;
        tree.resize(2 * n);

        for (int i = 0; i < n; i++)
            tree[n + i] = nums[i];

        for (int i = n - 1; i >= 1; i--)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
            tree[i] = tree[left] + tree[right];
        }
    }

    int sum(int node, int low, int high, int left, int right)
    {
        if (low > right || high < left || high < low)
            return 0;
        if (low >= left && high <= right)
            return tree[node];

        int mid = (low + high) / 2;
        int l = 2 * node;
        int r = 2 * node + 1;

        return sum(l, low, mid, left, right) + sum(r, mid + 1, high, left, right);
    }
    int sumRange(int left, int right)
    {
        return sum(1, 0, n - 1, left, right);
    }
};

int main()
{

    return 0;
}