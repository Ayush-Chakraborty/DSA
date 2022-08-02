#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_nbr(string &s1, string &s2)
{
    int cnt = 0;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == s2[i])
            cnt++;
    }

    return cnt == (n - 1);
}
int solve(string source, string dest, vector<string> &dict)
{
    int n = dict.size() + 2;

    vector<vector<int>> adj_list(n, vector<int>());
    for (int i = 1; i <= dict.size(); i++)
    {
        if (is_nbr(source, dict[i - 1]))
        {
            adj_list[0].push_back(i);
            adj_list[i].push_back(0);
        }
    }

    for (int i = 1; i <= dict.size(); i++)
    {
        if (is_nbr(dest, dict[i - 1]))
        {
            adj_list[n - 1].push_back(i);
            adj_list[i].push_back(n - 1);
        }
    }

    for (int i = 1; i <= dict.size(); i++)
    {
        for (int j = i + 1; j <= dict.size(); j++)
        {
            if (is_nbr(dict[i - 1], dict[j - 1]))
            {
                adj_list[i].push_back(j);
                adj_list[j].push_back(i);
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 1});
    vector<bool> visited(n, false);
    visited[0] = true;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        int v = node.first;
        int d = node.second;

        for (int child : adj_list[v])
        {
            if (child == n - 1)
                return d + 1;

            if (!visited[child])
            {
                visited[child] = true;
                q.push({child, d + 1});
            }
        }
    }
    return -1;
}

int main()
{

    return 0;
}