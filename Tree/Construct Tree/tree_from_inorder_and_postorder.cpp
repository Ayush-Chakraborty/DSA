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
int idx;
TreeNode *build_tree(vector<int> &inorder, vector<int> &postorder, int i, int j)
{
    if (i > j)
        return NULL;

    if (i == j)
    {
        idx--;
        return new TreeNode(inorder[i]);
    }

    int k;
    for (k = i; k <= j; k++)
    {
        if (inorder[k] == postorder[idx])
        {
            idx--;
            break;
        }
    }

    TreeNode *root = new TreeNode(inorder[k]);
    root->right = build_tree(inorder, postorder, k + 1, j);
    root->left = build_tree(inorder, postorder, i, k - 1);

    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    idx = n - 1;
    return build_tree(inorder, postorder, 0, n - 1);
}
int main()
{

    return 0;
}