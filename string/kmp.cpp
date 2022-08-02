#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> prefix(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        // j -> length

        if (s[i] == s[j])
            pi[i] = j + 1;
    }

    return pi;
}
int strstr(string str, string s)
{
    auto pi = prefix(s);
    int j = 0;
    for (int i = 0; i < str.size(); i++)
    {
        while (j > 0 && str[i] != s[j])
            j = pi[j - 1];

        if (str[i] == s[j])
        {
            j++;
            if (j == s.size())
                return i - s.size() + 1;
        }
    }
    return -1;
}
int main()
{
    return 0;
}