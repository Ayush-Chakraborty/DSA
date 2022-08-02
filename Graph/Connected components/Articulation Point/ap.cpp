#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t;
void dfs(int node, int parent, vector<int> adj_list[], vector<int> &disc, vector<int> &low, vector<bool> &is_articulation)
{
    disc[node] = low[node] = t;
    t++;
    int cnt = 0;
    for (auto child : adj_list[node])
    {
        if (child == parent)
            continue;

        if (disc[child] == -1)
        {
            cnt++;
            dfs(child, node, adj_list, disc, low, is_articulation);
            low[node] = min(low[node], low[child]);
            if (parent != -1 && low[child] >= disc[node])
                is_articulation[node] = true;
        }
        else
            low[node] = min(low[node], disc[child]);
    }

    if (parent == -1 && cnt > 1)
        is_articulation[node] = true;
}
vector<int> articulationPoints(int n, vector<int> adj_list[])
{
    vector<int> ans;
    t = 0;
    vector<int> disc(n, -1);
    vector<int> low(n);
    vector<bool> is_articulation(n, false);

    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
            dfs(i, -1, adj_list, disc, low, is_articulation);
    }

    for (int i = 0; i < n; i++)
    {
        if (is_articulation[i])
            ans.push_back(i);
    }
    if (ans.size() == 0)
        return {-1};
    return ans;
}

int main()
{

    return 0;
}