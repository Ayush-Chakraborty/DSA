#include <bits/stdc++.h>
using namespace std;
#define ll long long
class TreeAncestor
{
public:
    vector<vector<int>> up;
    int log_n;
    TreeAncestor(int n, vector<int> &parent)
    {
        log_n = log2(n);
        up.assign(n, vector<int>(log_n + 1, -1));
        for (int i = 0; i < n; i++)
            up[i][0] = parent[i];
        for (int i = 1; i <= log_n; i++)
        {
            for (int node = 0; node < n; node++)
                if (up[node][i - 1] != -1)
                    up[node][i] = up[up[node][i - 1]][i - 1];
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i <= log_n; i++)
        {
            if (k & (1 << i))
            {
                node = up[node][i];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};

int main()
{

    return 0;
}