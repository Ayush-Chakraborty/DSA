#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int n, vector<vector<int>> &edges)
{
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    vector<vector<int>> adj_list(n + 1, vector<int>());
    for (auto &edge : edges)
    {
        adj_list[edge[0]].push_back(edge[1]);
    }

    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            int node = q.front();
            q.pop();
            for (int child : adj_list[node])
            {
                if (child == n)
                    return 1;
                if (!visited[child])
                {
                    visited[child] = true;
                    q.push(child);
                }
            }
        }
    }
    return 0;
}

int main()
{

    return 0;
}