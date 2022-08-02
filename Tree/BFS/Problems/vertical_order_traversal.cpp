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
map<TreeNode *, int> m;
int mn, mx;
void func(TreeNode *node, int col)
{
    if (node == NULL)
        return;
    mn = min(mn, col);
    mx = max(mx, col);
    m[node] = col;
    func(node->left, col - 1);
    func(node->right, col + 1);
}
vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    m.clear();
    mn = INT_MAX;
    mx = INT_MIN;
    func(root, 0);

    int n = mx - mn + 1;
    vector<vector<int>> v(n, vector<int>());
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            TreeNode *node = q.front();
            q.pop();
            int col = m[node] - mn;
            v[col].push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return v;
}
int main()
{

    return 0;
}