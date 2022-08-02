#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(int node, vector<vector<int>> &adj_list, vector<int> &depth)
{
    for (auto child : adj_list[node])
    {
        depth[child] = depth[node] + 1;
        dfs(child, adj_list, depth);
    }
}
vector<int> solve(vector<vector<int>> &edges, vector<vector<int>> &queries)
{
    int n = edges.size() + 1;
    vector<vector<int>> adj_list(n);
    vector<int> depth(n);
    int log_n = log2(n);
    int up[n][log_n + 1];
    int max_edge[n][log_n + 1];
    depth[0] = 0;
    up[0][0] = max_edge[0][0] = 0;
    for (auto &edge : edges)
    {
        int u = edge[0] - 1;
        int v = edge[1] - 1;
        int w = edge[2];
        if (v < u)
            swap(u, v);
        adj_list[u].push_back(v);
        up[v][0] = u;
        max_edge[v][0] = w;
    }
    dfs(0, adj_list, depth);
    for (int i = 1; i <= log_n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            up[j][i] = up[up[j][i - 1]][i - 1];
            max_edge[j][i] = max(max_edge[j][i - 1], max_edge[up[j][i - 1]][i - 1]);
        }
    }

    vector<int> ans;
    for (auto q : queries)
    {
        int u = q[0] - 1;
        int v = q[1] - 1;
        int weight = 0;

        if (depth[v] > depth[u])
            swap(u, v);

        int k = depth[u] - depth[v];
        for (int i = 0; i < 32; i++)
        {
            if (k & (1 << i))
            {
                weight = max(weight, max_edge[u][i]);
                u = up[u][i];
            }
        }
        if (u == v)
        {
            ans.push_back(weight);
            continue;
        }
        for (int i = log_n; i >= 0; i--)
        {
            if (up[u][i] != up[v][i])
            {
                weight = max({weight, max_edge[u][i], max_edge[v][i]});
                u = up[u][i];
                v = up[v][i];
            }
        }
        weight = max({weight, max_edge[u][0], max_edge[v][0]});
        ans.push_back(weight);
    }
    return ans;
}

int main()
{

    return 0;
}