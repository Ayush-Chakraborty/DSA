#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool dfs(int node, vector<vector<int>> &adj_list, vector<bool> &visited, vector<bool> &rec_stack)
{
    rec_stack[node] = true;
    visited[node] = true;
    bool is_cyclic = false;
    for (auto child : adj_list[node])
    {
        if (rec_stack[child])
            is_cyclic = true;
        else if (!visited[child])
            is_cyclic = dfs(child, adj_list, visited, rec_stack);
        if (is_cyclic)
            break;
    }
    rec_stack[node] = false;
    return is_cyclic;
}

int solve(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj_list(n + 1, vector<int>());
    for (auto &edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
    }
    vector<bool> visited(n + 1, false);
    vector<bool> rec_stack(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj_list, visited, rec_stack))
                return 1;
        }
    }
    return 0;
}

int main()
{

    return 0;
}