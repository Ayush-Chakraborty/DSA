#include <bits/stdc++.h>
using namespace std;
#define ll long long
int spanningTree(int n, vector<vector<int>> adj[])
{
    int tot = 0;
    set<pair<int, int>> s;
    vector<bool> vis(n, false);
    vector<int> edge(n, INT_MAX);
    s.insert({0, 0});
    while (!s.empty())
    {
        auto node = *s.begin();
        s.erase(s.begin());
        int u = node.second;
        tot += node.first;
        vis[u] = true;

        for (auto &e : adj[u])
        {
            if (!vis[e[0]] && edge[e[0]] > e[1])
            {
                s.erase({edge[e[0]], e[0]});
                s.insert({e[1], e[0]});
                edge[e[0]] = e[1];
            }
        }
    }
    return tot;
}
int main()
{

    return 0;
}