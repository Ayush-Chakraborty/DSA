#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tot;
int node_cnt(int node, int parent, vector<vector<int>> &adj_list)
{
    int cnt = 0;
    for (auto child : adj_list[node])
    {
        if (child != parent)
        {
            int c = node_cnt(child, node, adj_list);
            if (c % 2 == 0)
            {
                tot++;
            }
            else
                cnt += c;
        }
    }
    return cnt + 1;
}
int solve(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj_list(n + 1, vector<int>());
    for (auto &edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }
    tot = 0;
    node_cnt(1, 0, adj_list);
    return tot;
}

int main()
{

    return 0;
}