#include <bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int row, int col, vector<string> &v)
{
    int INF = 1e9;
    vector<vector<int>> level(row, vector<int>(col, INF));
    reverse(v.begin(), v.end());
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {'D', 'U', 'L', 'R'};
    pair<int, int> start = {row - 1, 0};
    pair<int, int> end = {0, col - 1};
    deque<pair<int, int>> dq;
    dq.push_back(start);
    level[start.first][start.second] = 0;
    while (!dq.empty())
    {
        auto node = dq.front();
        dq.pop_front();
        if (node == end)
            break;
        for (int k = 0; k < 4; k++)
        {
            int r = node.first + dx[k];
            int c = node.second + dy[k];
            if (r < 0 || c < 0 || r >= row || c >= col)
                continue;
            vector<int> child;
            if (dir[k] == v[node.first][node.second])
                child = {r, c, 0};
            else
                child = {r, c, 1};
            if (level[node.first][node.second] + child[2] < level[child[0]][child[1]])
            {
                level[child[0]][child[1]] = level[node.first][node.second] + child[2];
                if (child[2] == 1)
                    dq.push_back({child[0], child[1]});
                else
                    dq.push_front({child[0], child[1]});
            }
        }
    }
    return level[end.first][end.second] == INF ? -1 : level[end.first][end.second];
}

int main()
{

    return 0;
}