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
int kthSmallest(TreeNode *node, int &k)
{
    if (node == NULL)
        return INT_MAX;
    int left = kthSmallest(node->left, k);
    if (left != INT_MAX)
        return left;
    k--;
    if (k == 0)
        return node->val;
    return kthSmallest(node->right, k);
}
int main()
{

    return 0;
}