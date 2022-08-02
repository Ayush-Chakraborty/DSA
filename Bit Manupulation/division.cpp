#include <bits/stdc++.h>
using namespace std;
#define ll long long
int divide(int A, int B)
{
    if (B == 0)
        return INT_MAX;

    bool is_negative = ((A < 0) ^ (B < 0));
    long long sign = is_negative ? -1 : 1;
    int ans = 0;
    long long a = A, b = B;
    a = abs(a);
    b = abs(b);

    if (b == 1)
    {
        if (sign * a > INT_MAX)
            return INT_MAX;
        return sign * a;
    }

    while (a >= b)
    {
        int i = 0;
        long long t = b;
        while ((t << 1) <= a)
        {
            t = (t << 1);
            i++;
        }
        ans += (1 << i);
        a -= t;
    }
    return sign * ans;
}

int main()
{

    return 0;
}