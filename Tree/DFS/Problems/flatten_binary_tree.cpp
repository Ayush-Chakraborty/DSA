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
void flatten_helper(TreeNode *node, TreeNode *&start, TreeNode *&end)
{
    if (node == NULL)
    {
        start = end = NULL;
        return;
    }

    start = end = node;
    TreeNode *left_start, *left_end, *right_start, *right_end;
    flatten_helper(node->left, left_start, left_end);
    flatten_helper(node->right, right_start, right_end);

    node->left = NULL;
    if (left_start)
    {
        node->right = left_start;
        left_end->right = right_start;
    }
    else if (right_start)
    {
        node->right = right_start;
    }

    if (left_end)
        end = left_end;

    if (right_end)
        end = right_end;
}
TreeNode *flatten(TreeNode *root)
{
    TreeNode *start, *end;
    flatten_helper(root, start, end);
    return start;
}

int main()
{

    return 0;
}