#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool dfs(int node, int parent, vector<vector<int>> &adj_list, vector<bool> &visited)
{
    visited[node] = true;
    for (auto child : adj_list[node])
    {
        if (child != parent)
        {
            if (visited[child])
                return true;
            if (dfs(child, node, adj_list, visited))
                return true;
        }
    }
    return false;
}

int solve(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj_list(n + 1, vector<int>());
    for (auto &edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj_list, visited))
                return 1;
        }
    }
    return 0;
}

int main()
{

    return 0;
}