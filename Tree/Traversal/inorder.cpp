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
vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *temp = root;
    vector<int> v;
    while (temp || !s.empty())
    {
        if (temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            v.push_back(s.top()->val);
            temp = s.top()->right;
            s.pop();
        }
    }
    return v;
}

int main()
{

    return 0;
}