#include <bits/stdc++.h>
using namespace std;
#define ll long long
int cnt;
void dfs(int node, vector<int> &prop, vector<vector<int>> &adj_list, int parent, int goodness, int max_goodness)
{
    bool is_leaf = true;
    goodness += prop[node - 1];
    for (auto child : adj_list[node])
    {
        if (child != parent)
        {
            is_leaf = false;
            dfs(child, prop, adj_list, node, goodness, max_goodness);
        }
    }
    if (is_leaf && goodness <= max_goodness)
        cnt++;
}

int solve(vector<int> &prop, vector<vector<int>> &edges, int max_goodness)
{
    int n = prop.size();
    vector<vector<int>> adj_list(n + 1, vector<int>());
    for (auto edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }
    cnt = 0;
    dfs(1, prop, adj_list, 0, 0, max_goodness);
    return cnt;
}

int main()
{

    return 0;
}