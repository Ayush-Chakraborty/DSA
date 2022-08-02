#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int msb = 32 - __builtin_clz(n);
    int log_n = msb - 1;
    int table[n][log_n + 1];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        table[i][0] = arr[i];
    }

    for (int i = 1; i <= log_n; i++)
    {
        for (int j = 0; j + (1 << i) - 1 < n; j++)
        {
            table[j][i] = min(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;

        int len = j - i + 1;
        int lg = 31 - __builtin_clz(len);
        cout << min(table[i][lg], table[j - (1 << lg) + 1][lg]) << "\n";
    }
}
int main()
{
    solve();
    return 0;
}