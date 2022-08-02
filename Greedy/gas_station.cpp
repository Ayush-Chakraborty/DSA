#include <bits/stdc++.h>
using namespace std;
#define ll long long
int canCompleteCircuit(const vector<int> &stations, const vector<int> &cost)
{
    int n = stations.size();
    long long tot = 0, start = 0, tot_gas = 0, tot_cost = 0;
    for (int i = 0; i < stations.size(); i++)
    {
        tot += (long long)(stations[i] - cost[i]);
        if (tot < 0)
        {
            tot = 0;
            start = i + 1;
        }
        tot_cost += cost[i];
        tot_gas += stations[i];
    }
    if (start == stations.size() || tot_cost > tot_gas)
        return -1;
    return start;
}

int main()
{

    return 0;
}