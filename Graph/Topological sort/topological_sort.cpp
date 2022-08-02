#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<int> indeg(v, 0);
    vector<vector<int>> adj_list(v);
    for (auto &edge : edges)
    {
        indeg[edge[1]]++;
        adj_list[edge[0]].push_back(edge[1]);
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto nbr : adj_list[node])
        {
            indeg[nbr]--;
            if (indeg[nbr] == 0)
                q.push(nbr);
        }
    }
    return ans;
}
int main()
{

    return 0;
}