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
TreeNode *solve(TreeNode *node1, TreeNode *node2)
{
    if (node1 == NULL && node2 == NULL)
        return node1;

    if (node1 == NULL)
        return node2;

    if (node2 == NULL)
        return node1;

    TreeNode *node = new TreeNode(node1->val + node2->val);
    node->left = solve(node1->left, node2->left);
    node->right = solve(node1->right, node2->right);
    return node;
}
int main()
{

    return 0;
}