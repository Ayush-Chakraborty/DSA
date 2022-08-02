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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> bfs;
    deque<TreeNode *> q;
    q.push_back(root);
    int level = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        bfs.push_back({});
        while (cnt--)
        {
            if (level % 2 == 0)
            {
                TreeNode *node = q.front();
                q.pop_front();
                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
                bfs.back().push_back(node->val);
            }
            else
            {
                TreeNode *node = q.back();
                q.pop_back();
                if (node->right)
                    q.push_front(node->right);
                if (node->left)
                    q.push_front(node->left);
                bfs.back().push_back(node->val);
            }
        }
        level++;
    }

    return bfs;
}

int main()
{

    return 0;
}