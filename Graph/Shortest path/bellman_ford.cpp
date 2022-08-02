#include <bits/stdc++.h>
using namespace std;
#define ll long long
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX)
                dist[v] = min(dist[v], dist[u] + w);
        }
    }
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            return 1;
    }
    return 0;
}
int main()
{

    return 0;
}