#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;
vector<int> shortest_path(int n, int source, vector<vector<pair<int, int>>> &adj_lsit)
{
    vector<int> dist(n + 1, INF);
    vector<bool> visited(n + 1, false);
    set<pair<int, int>> s;
    s.insert({0, source});
    dist[source] = 0;

    while (!s.empty())
    {
        auto node = *s.begin();
        s.erase(s.begin());

        int parent = node.second;
        int d_parent = node.first;
        if (visited[parent])
            continue;
        visited[parent] = true;

        for (auto child_node : adj_lsit[parent])
        {

            int child = child_node.first;
            int d = child_node.second;

            int d_child = dist[child];
            if (!visited[child] && d_parent + d < d_child)
            {
                dist[child] = d_parent + d;
                s.insert({dist[child], child});
            }
        }
    }
    return dist;
}

int solve(int n, vector<vector<int>> &edges, int source, int dest, vector<vector<int>> &extras)
{
    vector<vector<pair<int, int>>> adj_lsit(n + 1, vector<pair<int, int>>());
    for (auto &edge : edges)
    {
        adj_lsit[edge[0]].push_back({edge[1], edge[2]});
        adj_lsit[edge[1]].push_back({edge[0], edge[2]});
    }

    vector<int> d_source = shortest_path(n, source, adj_lsit);
    vector<int> d_dest = shortest_path(n, dest, adj_lsit);

    int mn = d_source[dest];
    for (auto &edge : extras)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (u > n || v > n)
            continue;

        int d1 = d_source[u];
        int d2 = d_dest[v];

        int d3 = d_source[v];
        int d4 = d_dest[u];

        if (d1 != INF && d2 != INF)
            mn = min(mn, d1 + d2 + w);

        if (d3 != INF && d4 != INF)
            mn = min(mn, d3 + d4 + w);
    }

    if (mn == INF)
        return -1;
    return mn;
}

int main()
{

    return 0;
}