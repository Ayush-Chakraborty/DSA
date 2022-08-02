#include <bits/stdc++.h>
using namespace std;
#define ll long long
int *parent, *sz;
void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find(int v)
{
    if (parent[v] == v)
        return v;

    return parent[v] = find(parent[v]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;

    if (sz[b] > sz[a])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}
bool comp(vector<int> &v1, vector<int> &v2)
{
    return v1[2] < v2[2];
}
int solve(int n, vector<vector<int>> &edges)
{
    parent = new int[n + 1];
    sz = new int[n + 1];

    for (int i = 1; i <= n; i++)
        make(i);

    sort(edges.begin(), edges.end(), comp);
    int cost = 0;
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        if (find(u) != find(v))
        {
            cost += edge[2];
            merge(u, v);
        }
    }

    delete[] sz;
    delete[] parent;

    return cost;
}

int main()
{

    return 0;
}