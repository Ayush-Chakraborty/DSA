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
map<int, vector<int>> m;
void func(TreeNode *root, int row, int col)
{
    if (root == NULL)
        return;
    m[row - col].push_back(root->val);
    func(root->left, row + 1, col - 1);
    func(root->right, row + 1, col + 1);
}
vector<int> solve(TreeNode *root)
{
    vector<int> v;
    m.clear();
    func(root, 0, 0);
    for (auto &p : m)
    {
        for (auto x : p.second)
            v.push_back(x);
    }
    return v;
}
int main()
{

    return 0;
}