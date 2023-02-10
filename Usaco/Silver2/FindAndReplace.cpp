#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N;

int main()
{
    cin >> N;

    for (int x = 0; x < N; x++)
    {
        vector<int> numGoing(1000, 0);
        string given, want;
        unordered_map<char, char> vals;
        vector<bool> foundGiven(1000, false);
        int curSum = 0;
        cin >> given >> want;
        bool bad = false;
        for (int x = 0; x < given.size(); x++)
        {
            if (vals.find(given[x]) == vals.end())
            {
                vals[given[x]] = want[x];
                if (given[x] != want[x])
                    curSum++;
                numGoing[want[x]]++;
                foundGiven[given[x]] = true;
            }
            else
            {
                if (vals[given[x]] != want[x])
                {
                    cout << -1 << endl;
                    bad = true;
                    break;
                }
            }
        }
        if (bad)
            continue;
        vector<int> vis(1000, -1);
        for (pair<char, char> x : vals)
        {
            if (vis[x.first] == -1)
            {
                char curr = x.first;
                vector<char> cycleVals;
                bool cycleFound = false;
                while (vis[curr] == -1 && foundGiven[curr])
                {
                    cycleVals.push_back(curr);
                    vis[curr] = cycleVals.size() - 1;
                    curr = vals[curr];
                    if (vis[curr] != -1)
                    {
                        if (find(cycleVals.begin(), cycleVals.end(), curr) != cycleVals.end())
                        {
                            if (cycleVals[cycleVals.size() - 1] != curr)
                            {
                                cycleFound = true;
                            }
                        }
                    }
                }
                if (cycleFound)
                {
                    bool isExtra = true;
                    for (int x = vis[curr]; x < cycleVals.size(); x++)
                    {
                        if (numGoing[cycleVals[x]] >= 2)
                        {
                            isExtra = false;
                            break;
                        }
                    }

                    if (isExtra)
                    {
                        bool foundTwoOutgoing = false;
                        for (int x : numGoing)
                        {
                            if (x >= 2)
                            {
                                foundTwoOutgoing = true;
                            }
                        }
                        if (!foundTwoOutgoing && vals.size() >= 26 * 2)
                        {
                            cout << -1 << endl;
                            bad = true;
                            break;
                        }
                        else
                            curSum++;
                    }
                }
            }
        }
        if (!bad)
            cout << curSum << endl;
    }
}