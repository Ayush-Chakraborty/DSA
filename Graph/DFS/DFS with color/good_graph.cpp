#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dfs(int node, vector<int> &adj_list, vector<int> &color, int c)
{
    color[node] = c;
    int child = adj_list[node - 1];
    if (color[child] == 0)
    {
        dfs(child, adj_list, color, c);
    }
    color[node] = color[child];
    return color[node];
}

int solve(vector<int> &graph)
{
    int n = graph.size();
    set<int> s;
    vector<int> color(n + 1, 0);
    color[1] = 1;
    int c = 2;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            int node_color = dfs(i, graph, color, c);
            if (node_color != 1)
                s.insert(node_color);
            c++;
        }
    }
    return s.size();
}

int main()
{

    return 0;
}