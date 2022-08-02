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

// iterative inorder traversal
class BSTIterator
{
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root)
    {
        TreeNode *temp = root;
        while (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
    }

    /** return whether we have a next smallest number */
    bool hasNext()
    {
        return !s.empty();
    }

    /** return the next smallest number */
    int next()
    {
        TreeNode *node = s.top();
        s.pop();
        TreeNode *temp = node->right;
        while (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        return node->val;
    }
};
int main()
{

    return 0;
}