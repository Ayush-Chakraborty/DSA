#include <bits/stdc++.h>
using namespace std;
#define ll long long
int singleNumber(const vector<int> &v)
{
    vector<int> bit_cnt(32, 0);
    for (auto x : v)
    {
        for (int i = 0; i < 32; i++)
        {
            if (x & (1 << i))
                bit_cnt[i]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if (bit_cnt[i] % 3)
            ans |= (1 << i);
    }
    return ans;
}

int main()
{

    return 0;
}