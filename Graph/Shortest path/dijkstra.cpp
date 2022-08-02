#include <bits/stdc++.h>
using namespace std;
#define ll long long

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{

    vector<vector<pair<int, int>>> adj_list(n + 1, vector<pair<int, int>>());
    for (auto &edge : times)
    {
        adj_list[edge[0]].push_back({edge[1], edge[2]});
    }

    const int INF = 1e9;
    set<pair<int, int>> s;
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, INF);

    s.insert({0, k});
    dist[k] = 0;

    while (!s.empty())
    {
        auto node = *s.begin();
        s.erase(s.begin());
        int u = node.second;

        if (visited[u])
            continue;
        visited[u] = true;
        for (auto &child : adj_list[u])
        {
            int v = child.first;
            int d = child.second;

            if (!visited[v] && dist[v] > dist[u] + d)
            {
                s.insert({dist[u] + d, v});
                dist[v] = dist[u] + d;
            }
        }
    }

    int mx = *max_element(dist.begin() + 1, dist.end());
    if (mx == INF)
        return -1;
    return mx;
}
int main()
{

    return 0;
}