#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[10001][101];
int func(int egg, int floor)
{
    if (floor == 0)
        return 0;
    if (egg == 0)
        return INT_MAX;
    if (floor == 1)
        return 1;
    if (egg == 1)
        return floor;
    if (dp[floor][egg] != -1)
        return dp[floor][egg];
    int mn = INT_MAX;
    int l = 1, r = floor;
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (func(egg - 1, mid - 1) >= func(egg, floor - mid))
            r = mid;
        else
            l = mid + 1;
    }
    // for(int k=1;k<=floor;k++){
    //     int m=max(func(egg-1,k-1),func(egg,floor-k));
    //     if(m!=INT_MAX)
    //     mn=min(mn,m+1);
    // }
    int m1 = max(func(egg - 1, l - 1), func(egg, floor - l));
    if (m1 != INT_MAX)
        m1++;
    int m2 = max(func(egg - 1, r - 1), func(egg, floor - r));
    if (m2 != INT_MAX)
        m2++;
    return dp[floor][egg] = min(m1, m2);
}
int solve(int a, int b)
{
    memset(dp, -1, sizeof(dp));
    return func(a, b);
}

int main()
{

    return 0;
}