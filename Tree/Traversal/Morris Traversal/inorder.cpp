#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> inorder;
    TreeNode *temp = root;
    while (temp)
    {
        if (temp->left == NULL)
        {
            inorder.push_back(temp->val);
            temp = temp->right;
            continue;
        }
        TreeNode *left = temp->left;
        while (left->right != NULL && left->right != temp)
            left = left->right;
        if (left->right == NULL)
        {
            left->right = temp;
            temp = temp->left;
        }
        else
        {
            left->right = NULL;
            inorder.push_back(temp->val);
            temp = temp->right;
        }
    }
    return inorder;
}
int main()
{

    return 0;
}