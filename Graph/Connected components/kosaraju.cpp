#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int>> ans;
void dfs(int node, vector<vector<int>> &adj_list, vector<bool> &visited, stack<int> &sk, bool push)
{
    visited[node] = true;
    for (auto child : adj_list[node])
    {
        if (!visited[child])
            dfs(child, adj_list, visited, sk, push);
    }
    if (push)
        sk.push(node);
    else
        ans.back().push_back(node);
}
vector<vector<int>> SCC(int n, vector<vector<int>> edges)
{
    vector<vector<int>> adj_list(n, vector<int>());
    for (auto edge : edges)
        adj_list[edge[0]].push_back(edge[1]);

    vector<bool> visited(n, false);
    stack<int> sk;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, adj_list, visited, sk, true);
    }

    adj_list.assign(n, vector<int>());
    for (auto edge : edges)
        adj_list[edge[1]].push_back(edge[0]);

    visited.assign(n, false);
    ans.clear();

    while (!sk.empty())
    {
        int node = sk.top();
        sk.pop();
        if (!visited[node])
        {
            ans.push_back({});
            dfs(node, adj_list, visited, sk, false);
        }
    }

    return ans;
}
int main()
{
    auto v = SCC(5, {{0, 1}, {1, 2}, {1, 4}, {2, 3}, {3, 2}, {4, 0}});
    for (auto comp : v)
    {
        for (auto x : comp)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}