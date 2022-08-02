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
int isSymmetric(TreeNode *root)
{
    vector<TreeNode *> que;
    que.push_back(root);
    while (!que.empty())
    {
        vector<TreeNode *> temp;
        for (auto node : que)
        {
            if (node)
            {
                temp.push_back(node->left);
                temp.push_back(node->right);
            }
        }
        int i = 0;
        int j = que.size() - 1;
        while (j > i)
        {
            if ((que[i] == NULL && que[j] == NULL) || (que[i] && que[j] && que[i]->val == que[j]->val))
            {
                i++;
                j--;
            }
            else
                return 0;
        }
        que = temp;
    }
    return 1;
}
int main()
{

    return 0;
}