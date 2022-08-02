#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int mx;
void func(TreeNode *node, int target, int &height, int &dist)
{
    if (node == NULL)
    {
        height = 0;
        dist = -1;
        return;
    }

    int lh, ld, rh, rd;
    func(node->left, target, lh, ld);
    func(node->right, target, rh, rd);
    if (ld == -1 && rd != -1)
    {
        mx = max(rd + lh + 1, mx);
    }
    if (rd == -1 && ld != -1)
        mx = max(mx, ld + rh + 1);
    height = max(lh, rh) + 1;

    if (node->val == target)
        dist = 0;
    else if (ld == -1 && rd == -1)
        dist = -1;
    else if (ld != -1)
        dist = ld + 1;
    else
        dist = rd + 1;
}
int solve(TreeNode *root, int b)
{
    mx = 0;
    int h, d;
    func(root, b, h, d);
    return mx;
}
int main()
{

    return 0;
}