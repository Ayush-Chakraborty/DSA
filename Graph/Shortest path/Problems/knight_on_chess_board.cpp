#include <bits/stdc++.h>
using namespace std;
#define ll long long
int knight(int n, int m, int x1, int y1, int x2, int y2)
{
    if (x1 == x2 && y1 == y2)
        return 0;
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    queue<pair<int, int>> q;
    int dx[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    int dy[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    q.push({x1, y1});
    visited[x1][y1] = true;
    int level = 1;
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            auto pos = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int r = pos.first + dx[i];
                int c = pos.second + dy[i];

                if (r <= 0 || c <= 0 || r > n || c > m)
                    continue;

                if (r == x2 && c == y2)
                    return level;

                if (!visited[r][c])
                    q.push({r, c});

                visited[r][c] = true;
            }
        }
        level++;
    }
    return -1;
}

int main()
{

    return 0;
}