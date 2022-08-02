#include <bits/stdc++.h>
using namespace std;
#define ll long long
int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    int mx = 0;
    stack<int> s;
    heights.push_back(INT_MIN);
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() && heights[s.top()] > heights[i])
        {
            int h = heights[s.top()];
            s.pop();
            int left = 0, right = i - 1;
            if (!s.empty())
                left = s.top() + 1;
            mx = max(mx, (right - left + 1) * h);
        }
        s.push(i);
    }
    heights.pop_back();
    return mx;
}
int main()
{

    return 0;
}