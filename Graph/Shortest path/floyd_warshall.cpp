#include <bits/stdc++.h>
using namespace std;
#define ll long long

void APSP(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = dist[v][u] = w;
    }
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int k = 0; k < n; k++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (dist[u][k] != INT_MAX && dist[k][v] != INT_MAX)
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }
}
int main()
{

    return 0;
}