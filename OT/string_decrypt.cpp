#include <bits/stdc++.h>
using namespace std;
map<int, int> bracket;
string decrypt(string &s, int start, int end)
{
    if (end < start)
        return "";

    auto it = bracket.upper_bound(start);
    if (it == bracket.end() || it->first > end)
        return s.substr(start, end - start + 1);
    int open_bracket = it->first;
    int close_bracket = it->second;
    string cnt;
    int i = open_bracket - 1;
    while (s[i] >= '0' && s[i] <= '9')
    {
        cnt += s[i];
        i--;
    }
    reverse(cnt.begin(), cnt.end());
    int repeat = stoi(cnt);
    string inner_string = decrypt(s, open_bracket + 1, close_bracket - 1);
    string decrypted = s.substr(start, i - start + 1);
    while (repeat--)
        decrypted += inner_string;

    return decrypted;
}

int main()
{
    string str = "2[ab3[cd]]";
    // cin>>str;
    int n = str.size();
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '[')
            s.push(i);
        else if (str[i] == ']')
        {
            bracket[s.top()] = i;
            s.pop();
        }
    }
    cout << decrypt(str, 0, n - 1);
    return 0;
}