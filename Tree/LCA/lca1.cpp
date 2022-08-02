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
int ancestor;
void lca_helper(TreeNode *node, int node1, int &dist1, int node2, int &dist2)
{
    if (node == NULL)
    {
        dist1 = dist2 = -1;
        return;
    }
    if (node->val == node1 && node1 == node2)
    {
        dist1 = 0;
        dist2 = 0;
        ancestor = node1;
        return;
    }

    int l1, l2, r1, r2;
    lca_helper(node->left, node1, l1, node2, l2);
    lca_helper(node->right, node1, r1, node2, r2);

    if (l1 != -1 && l2 == -1 && r1 == -1 && r2 != -1)
        ancestor = node->val;

    if (l1 == -1 && l2 != -1 && r1 != -1 && r2 == -1)
        ancestor = node->val;

    if (node->val == node1 && (l2 != -1 || r2 != -1))
        ancestor = node->val;

    if (node->val == node2 && (l1 != -1 || r1 != -1))
        ancestor = node->val;

    if (node->val == node1)
        dist1 = 0;
    else if (l1 == -1 && r1 == -1)
        dist1 = -1;
    else if (l1 == -1)
        dist1 = r1;
    else
        dist1 = l1;

    if (node->val == node2)
        dist2 = 0;
    else if (l2 == -1 && r2 == -1)
        dist2 = -1;
    else if (l2 == -1)
        dist2 = r2;
    else
        dist2 = l2;
}
int lca(TreeNode *root, int node1, int node2)
{
    int d1, d2;
    ancestor = -1;
    lca_helper(root, node1, d1, node2, d2);
    return ancestor;
}
int main()
{

    return 0;
}