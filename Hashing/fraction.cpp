#include <bits/stdc++.h>
using namespace std;
#define ll long long
string fractionToDecimal(int a, int b)
{
    ll top = abs((ll)a);
    ll bottom = abs((ll)b);

    if (top == 0)
        return "0";

    bool is_negative = ((a < 0) ^ (b < 0));
    string sign = is_negative ? "-" : "";
    ll whole_num = top / bottom;
    top = (top % bottom) * 10ll;
    string s;

    if (top == 0)
        return sign + to_string(whole_num);

    unordered_map<int, int> m;

    while (top)
    {
        if (m.find(top) != m.end())
        {
            s = s.substr(0, m[top]) + "(" + s.substr(m[top], s.size() - m[top]) + ")";
            break;
        }
        m[top] = s.size();
        s.push_back(top / bottom + '0');
        top = (top % bottom) * 10;
    }

    if (whole_num)
        return sign + to_string(whole_num) + "." + s;
    return sign + "0." + s;
}

int main()
{

    return 0;
}