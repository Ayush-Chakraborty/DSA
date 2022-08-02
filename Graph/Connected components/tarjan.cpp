#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> ans;
int t;
void dfs(int node, vector<vector<int>> &adj_list, vector<int> &disc, vector<int> &low, vector<bool> &in_stack, stack<int> &s)
{
    disc[node] = low[node] = t;
    t++;
    s.push(node);
    in_stack[node] = true;

    for (auto child : adj_list[node])
    {
        if (disc[child] == -1)
            dfs(child, adj_list, disc, low, in_stack, s);
        if (in_stack[child])
            low[node] = min(low[node], low[child]);
    }

    if (disc[node] == low[node])
    {
        ans.push_back({});
        while (1)
        {
            int u = s.top();
            s.pop();
            ans.back().push_back(u);
            in_stack[u] = false;
            if (u == node)
                break;
        }
    }
}
vector<vector<int>> scc(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj_list(n, vector<int>());
    for (auto edge : edges)
        adj_list[edge[0]].push_back(edge[1]);

    vector<int> disc(n, -1);
    vector<int> low(n);
    vector<bool> in_stack(n, false);
    stack<int> s;
    t = 0;
    ans.clear();

    for (int i = 0; i < n; i++)
    {
        if (disc[i] == -1)
            dfs(i, adj_list, disc, low, in_stack, s);
    }

    return ans;
}
int main()
{

    return 0;
}