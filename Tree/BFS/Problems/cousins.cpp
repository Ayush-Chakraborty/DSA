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
vector<int> solve(TreeNode *root, int target)
{
    queue<TreeNode *> q;
    q.push(root);
    bool found = false;
    vector<int> cousins;
    while (!q.empty())
    {
        int cnt = q.size();
        if (found)
        {
            while (!q.empty())
            {
                cousins.push_back(q.front()->val);
                q.pop();
            }
            return cousins;
        }
        while (cnt--)
        {
            TreeNode *node = q.front();
            q.pop();
            if ((node->left && node->left->val == target) || (node->right && node->right->val == target))
            {
                found = true;
                continue;
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return cousins;
}
int main()
{

    return 0;
}