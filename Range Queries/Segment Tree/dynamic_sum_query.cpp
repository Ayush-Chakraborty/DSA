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
        n = sz;
        while (__builtin_popcount(n) != 1)
            n++;
        tree.assign(2 * n, 0);

        for (int i = 0; i < sz; i++)
            tree[n + i] = nums[i];

        for (int i = n - 1; i >= 1; i--)
        {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void update(int index, int val)
    {
        tree[n + index] = val;
        for (int i = (n + index) / 2; i >= 1; i /= 2)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    int sum(int node, int low, int high, int left, int right)
    {
        if (low > right || high < left)
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