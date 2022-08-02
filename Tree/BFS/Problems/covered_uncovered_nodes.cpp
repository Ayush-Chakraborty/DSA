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
long long coveredNodes(TreeNode *root)
{
    long long covered, uncovered;
    covered = uncovered = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int cnt = q.size();
        int i = 0;
        while (i != cnt)
        {
            TreeNode *node = q.front();
            q.pop();

            if (i == 0 || i == cnt - 1)
                uncovered += (long long)node->val;
            else
                covered += (long long)node->val;

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);

            i++;
        }
    }
    return abs(covered - uncovered);
}
int main()
{

    return 0;
}