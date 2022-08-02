#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root)
{
    TreeLinkNode *curr_level, *prev_level, *curr_node;
    root->next = NULL;
    curr_level = root;
    while (curr_level)
    {
        prev_level = curr_level;
        curr_node = NULL;
        curr_level = NULL;

        while (prev_level)
        {
            if (prev_level->left)
            {
                if (curr_node)
                {
                    curr_node->next = prev_level->left;
                    curr_node = curr_node->next;
                }
                else
                {
                    curr_node = prev_level->left;
                    curr_level = curr_node;
                }
            }

            if (prev_level->right)
            {
                if (curr_node)
                {
                    curr_node->next = prev_level->right;
                    curr_node = curr_node->next;
                }
                else
                {
                    curr_node = prev_level->right;
                    curr_level = curr_node;
                }
            }
            prev_level = prev_level->next;
        }
    }
}

int main()
{

    return 0;
}