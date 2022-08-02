#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(int node, vector<vector<int>> &adj_list, vector<bool> &vis)
{
    vis[node] = true;
    for (auto child : adj_list[node])
    {
        if (!vis[child])
            dfs(child, adj_list, vis);
    }
}

int motherVertex(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj_list(n + 1, vector<int>());
    for (auto &edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
    }
    vector<bool> vis(n + 1, false);
    int v;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            v = i;
            dfs(i, adj_list, vis);
        }
    }
    vis.assign(n + 1, false);
    dfs(v, adj_list, vis);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            return 0;
    }
    return 1;
}

int main()
{

    return 0;
}