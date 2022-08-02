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
vector<int> recoverTree(TreeNode *root)
{
    TreeNode *temp = root;
    int x, y, prev;
    x = y = prev = INT_MIN;
    while (temp)
    {
        if (temp->left == NULL)
        {
            if (temp->val < prev)
            {
                if (x == INT_MIN)
                {
                    x = prev;
                    y = temp->val;
                }
                else
                {
                    y = temp->val;
                }
            }
            prev = temp->val;
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
            if (temp->val < prev)
            {
                if (x == INT_MIN)
                {
                    x = prev;
                    y = temp->val;
                }
                else
                {
                    y = temp->val;
                }
            }
            prev = temp->val;
            left->right = NULL;
            temp = temp->right;
        }
    }
    if (x > y)
        swap(x, y);
    return {x, y};
}
int main()
{

    return 0;
}