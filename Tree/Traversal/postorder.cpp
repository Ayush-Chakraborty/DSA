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
vector<int> postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *temp = root;
    vector<int> v;
    TreeNode *prev = NULL;
    while (temp || !s.empty())
    {
        if (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            TreeNode *node = s.top();
            if (node->right && node->right != prev)
                temp = node->right;
            else
            {
                s.pop();
                v.push_back(node->val);
                prev = node;
            }
        }
    }
    return v;
}

int main()
{

    return 0;
}