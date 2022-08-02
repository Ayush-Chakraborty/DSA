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
bool get_path(TreeNode *root, int target, vector<int> &path)
{
    if (root == NULL)
        return false;
    path.push_back(root->val);
    if (root->val == target)
        return true;
    if (get_path(root->left, target, path))
        return true;
    if (get_path(root->right, target, path))
        return true;
    path.pop_back();
    return false;
}
vector<int> solve(TreeNode *root, int b)
{
    vector<int> path;
    get_path(root, b, path);
    return path;
}
int main()
{

    return 0;
}