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
void inorder_traversal(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left, v);
    v.push_back(root->val);
    inorder_traversal(root->right, v);
}
int t2Sum(TreeNode *a, int b)
{
    vector<int> inorder;
    inorder_traversal(a, inorder);
    int i = 0;
    int j = inorder.size() - 1;
    while (i < j)
    {
        if (inorder[i] + inorder[j] == b)
            return 1;
        else if (inorder[i] + inorder[j] > b)
            j--;
        else
            i++;
    }
    return 0;
}

int main()
{

    return 0;
}