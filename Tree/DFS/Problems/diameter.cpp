#include <bits/stdc++.h>
using namespace std;
#define ll long long
int max_distance(int node, int parent, vector<vector<int>> &adj_list, int &height)
{
    int mx = 0;
    height = 0;
    int h1, h2;
    h1 = h2 = 0;
    for (auto child : adj_list[node])
    {
        if (child != parent)
        {
            int h;
            mx = max(mx, max_distance(child, node, adj_list, h));
            height = max(height, h);
            if (h > h1)
            {
                h2 = h1;
                h1 = h;
            }
            else if (h > h2)
                h2 = h;
        }
    }
    height++;
    return max(mx, h1 + h2 + 1);
}

int solve(vector<int> &tree)
{
    int n = tree.size();
    vector<vector<int>> adj_list(n, vector<int>());
    int root;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] == -1)
            root = i;
        else
        {
            adj_list[tree[i]].push_back(i);
            adj_list[i].push_back(tree[i]);
        }
    }
    int h;
    return max_distance(root, -1, adj_list, h) - 1;
}

int main()
{

    return 0;
}