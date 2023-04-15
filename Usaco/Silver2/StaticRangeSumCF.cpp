#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#define ll long long
using namespace std;

map<ll, ll> added, newSum, Prefix;

int main()
{
    int N, Q;

    cin >> N >> Q;
    for (int x = 0; x < N; x++)
    {
        ll start, end, val;
        cin >> start >> end >> val;
        if (added.find(start) == added.end())
            added[start] = 0;
        if (added.find(end) == added.end())
            added[end] = 0;
        added[start] += val;
        added[end] -= val;
    }
    ll sum = 0;
    vector<int> keyPoints;
    for (auto x : added)
    {
        sum += x.second;
        newSum[x.first] = sum;
        keyPoints.push_back(x.first);
    }
    ll curSum = 0;
    for (int x = 0; x < keyPoints.size(); x++)
    {
        ll val = keyPoints[x];
        Prefix[val] = curSum + newSum[val];

        curSum += newSum[val] * (keyPoints[x + 1] - val);
    }
    vector<ll> ans;
    for (int x = 0; x < Q; x++)
    {
        ll start, end;
        cin >> start >> end;
        end--;
        start--;
        if (start > keyPoints[keyPoints.size() - 1] || end < keyPoints[0])
            ans.push_back(0);
        else
        {
            auto val1 = Prefix.upper_bound(start), val2 = --Prefix.upper_bound(end);
            if (val1 != Prefix.begin())
                --val1;

            ll PrefixFirst = val1->second + ((start - val1->first) * newSum[val1->first]),
               PrefixSecond = val2->second + ((end - val2->first) * newSum[val2->first]);
            if (start < keyPoints[0])
                ans.push_back(PrefixSecond);
            else
                ans.push_back(PrefixSecond - PrefixFirst);
        }
    }
    for (ll x : ans)
    {
        cout << x << endl;
    }
}