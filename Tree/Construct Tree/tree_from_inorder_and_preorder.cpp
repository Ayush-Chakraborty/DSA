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
TreeNode *build_tree(vector<int> &preorder, vector<int> &inorder, int i1, int j1, int i2, int j2)
{
    if (i1 > j1)
        return NULL;

    if (i1 == j1)
        return new TreeNode(preorder[i1]);

    int idx;
    for (int k = 0; k <= j1 - i1; k++)
    {
        if (preorder[i1] == inorder[i2 + k])
        {
            idx = k;
            break;
        }
    }

    TreeNode *root = new TreeNode(preorder[i1]);
    root->left = build_tree(preorder, inorder, i1 + 1, i1 + idx, i2, i2 + idx - 1);
    root->right = build_tree(preorder, inorder, i1 + idx + 1, j1, i2 + idx + 1, j2);

    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return build_tree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}
int main()
{

    return 0;
}