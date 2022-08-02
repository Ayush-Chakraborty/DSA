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
int get_height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = get_height(root->left);
    int right = get_height(root->right);
    if (left == -1 || right == -1)
        return -1;
    if (abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}
int isBalanced(TreeNode *root)
{
    int h = get_height(root);
    return h != -1;
}
int main()
{

    return 0;
}