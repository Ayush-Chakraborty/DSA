#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(int node, vector<vector<int>> &adj_list, vector<int> &depth)
{
    for (auto &child : adj_list[node])
    {
        depth[child] = depth[node] + 1;
        dfs(child, adj_list, depth);
    }
}
void solve()
{
    int n;
    cin >> n;
    int log_n = log2(n);
    int up[n][log_n + 1];
    vector<int> depth(n);
    depth[0] = 0;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int child;
            cin >> child;
            up[child][0] = i;
            adj_list[i].push_back(child);
        }
    }
    dfs(0, adj_list, depth);
    up[0][0] = 0;
    for (int i = 1; i <= log_n; i++)
    {
        for (int j = 0; j < n; j++)
            up[j][i] = up[up[j][i - 1]][i - 1];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (depth[v] > depth[u])
            swap(u, v);
        int k = depth[u] - depth[v];
        for (int i = 0; i < 32; i++)
        {
            if (k & (1 << i))
                u = up[u][i];
        }
        if (u == v)
        {
            cout << u << "\n";
            continue;
        }
        for (int i = log_n; i >= 0; i--)
        {
            if (up[u][i] != up[v][i])
            {
                u = up[u][i];
                v = up[v][i];
            }
        }
        cout << up[u][0] << "\n";
    }
}
int main()
{
    solve();
    return 0;
}