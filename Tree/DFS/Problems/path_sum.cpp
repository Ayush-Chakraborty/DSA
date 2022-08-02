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
vector<vector<int>> paths;
void func(TreeNode *node, int sum, vector<int> &path)
{
    if (node == NULL)
        return;
    path.push_back(node->val);
    if (node->left == NULL && node->right == NULL && sum == node->val)
    {
        paths.push_back(path);
        path.pop_back();
        return;
    }
    func(node->left, sum - node->val, path);
    func(node->right, sum - node->val, path);
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int target)
{
    paths.clear();
    vector<int> path = {};
    func(root, target, path);
    return paths;
}
int main()
{

    return 0;
}