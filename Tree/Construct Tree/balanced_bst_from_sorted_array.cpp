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
TreeNode *build_tree(const vector<int> &v, int i, int j)
{
    if (i > j)
        return NULL;

    if (i == j)
        return new TreeNode(v[i]);

    int mid = (i + j) / 2;

    TreeNode *root = new TreeNode(v[mid]);
    root->left = build_tree(v, i, mid - 1);
    root->right = build_tree(v, mid + 1, j);

    return root;
}
TreeNode *sortedArrayToBST(const vector<int> &v)
{
    return build_tree(v, 0, v.size() - 1);
}
int main()
{

    return 0;
}