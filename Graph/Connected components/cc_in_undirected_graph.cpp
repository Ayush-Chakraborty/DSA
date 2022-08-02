#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(int node, vector<vector<int>> &adj_list, vector<bool> &visited)
{
    visited[node] = true;
    for (auto child : adj_list[node])
    {
        if (!visited[child])
            dfs(child, adj_list, visited);
    }
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
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj_list, visited);
            cnt++;
        }
    }
    return cnt;
}

int main()
{

    return 0;
}