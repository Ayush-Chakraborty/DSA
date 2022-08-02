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
vector<vector<string>> findLadders(string source, string dest, vector<string> &dict)
{
    if (source == dest)
        return {{source}};
    if (is_nbr(source, dest))
        return {{source, dest}};

    dict.pop_back();
    dict.pop_back();
    unordered_set<string> s;
    for (auto &str : dict)
        s.insert(str);

    dict.clear();
    for (auto &str : s)
        dict.push_back(str);

    if (dict.size() == 0)
    {
        return {};
    }
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
    q.push({0, 0});
    vector<bool> visited(n, false);
    visited[0] = true;
    vector<int> dist(n, -1);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        int v = node.first;
        int d = node.second;
        dist[v] = d;
        for (int child : adj_list[v])
        {
            if (!visited[child])
            {
                visited[child] = true;
                q.push({child, d + 1});
            }
        }
        if (dist[n - 1] != -1)
            break;
    }
    if (dist[n - 1] == -1)
        return {};

    int d = dist[n - 1];
    vector<vector<int>> paths;
    paths.push_back({n - 1});
    d--;
    while (d >= 0)
    {
        int i = 0;
        int sz = paths.size();
        while (i < sz)
        {
            int node = paths[i].back();
            int j = 0;
            for (auto child : adj_list[node])
            {
                if (dist[child] == d)
                {
                    if (!j)
                    {
                        paths[i].push_back(child);
                        j++;
                    }
                    else
                    {
                        paths.push_back(paths[i]);
                        paths.back().back() = child;
                    }
                }
            }
            i++;
        }
        d--;
    }

    vector<vector<string>> final_paths;
    for (auto &path : paths)
    {
        if (path.back() != 0)
            continue;
        final_paths.push_back({});
        for (int i = path.size() - 1; i >= 0; i--)
        {
            if (path[i] == 0)
                final_paths.back().push_back(source);
            else if (path[i] == n - 1)
                final_paths.back().push_back(dest);
            else
                final_paths.back().push_back(dict[path[i] - 1]);
        }
    }
    return final_paths;
}

int main()
{

    return 0;
}