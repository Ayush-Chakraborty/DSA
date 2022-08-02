#include <bits/stdc++.h>
using namespace std;
#define ll long long
string minWindow(string s, string t)
{
    int i, j;
    i = j = 0;
    unordered_map<char, int> target;
    for (auto ch : t)
        target[ch]++;

    unordered_map<char, int> m;
    int cnt = 0;
    int n = s.size();
    int mn = INT_MAX;
    int start, end;

    while (j < n)
    {
        while (cnt != target.size() && j < n)
        {
            if (target.find(s[j]) != target.end())
            {
                m[s[j]]++;
                if (m[s[j]] == target[s[j]])
                    cnt++;
            }
            j++;
        }

        while (cnt == target.size() && i < j)
        {
            if (j - i < mn)
            {
                mn = j - i;
                start = i;
                end = j;
            }
            if (target.find(s[i]) != target.end())
            {
                if (m[s[i]] == target[s[i]])
                    cnt--;
                m[s[i]]--;
            }
            i++;
        }
    }

    if (mn == INT_MAX)
        return "";
    return s.substr(start, end - start);
}

int main()
{

    return 0;
}