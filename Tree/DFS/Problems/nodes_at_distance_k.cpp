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
vector<int> v;
void find_node(TreeNode *root, int dist)
{
    if (root == NULL)
        return;
    if (dist == 0)
    {
        v.push_back(root->val);
        return;
    }
    find_node(root->left, dist - 1);
    find_node(root->right, dist - 1);
}
int find_dist(TreeNode *root, int target, int dist)
{
    if (root == NULL)
        return -1;
    if (root->val == target)
    {
        find_node(root, dist);
        return 0;
    }
    int d = find_dist(root->left, target, dist);
    if (d != -1)
    {
        if (d + 1 == dist)
        {
            v.push_back(root->val);
            return -1;
        }
        find_node(root->right, dist - d - 2);
        return d + 1;
    }
    d = find_dist(root->right, target, dist);
    if (d != -1)
    {
        if (d + 1 == dist)
        {
            v.push_back(root->val);
            return -1;
        }
        find_node(root->left, dist - d - 2);
        return d + 1;
    }
    return -1;
}
vector<int> distanceK(TreeNode *root, int target, int dist)
{
    v.clear();
    find_dist(root, target, dist);
    return v;
}

int main()
{

    return 0;
}