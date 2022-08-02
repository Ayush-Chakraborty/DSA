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
TreeNode *build_tree(vector<int> &inorder, int i, int j)
{
    if (i == j)
        return new TreeNode(inorder[i]);
    if (i > j)
        return NULL;
    int idx = i;
    int mx = inorder[i];

    for (int k = i + 1; k <= j; k++)
    {
        if (inorder[k] > mx)
        {
            mx = inorder[k];
            idx = k;
        }
    }

    TreeNode *root = new TreeNode(mx);
    root->left = build_tree(inorder, i, idx - 1);
    root->right = build_tree(inorder, idx + 1, j);

    return root;
}
TreeNode *buildTree(vector<int> &inorder)
{
    return build_tree(inorder, 0, inorder.size() - 1);
}

int main()
{

    return 0;
}