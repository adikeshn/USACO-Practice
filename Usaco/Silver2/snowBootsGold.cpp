#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100001

vector<int> before(MAXN), after(MAXN), steps(MAXN), indexs(MAXN);

vector<pair<pair<int, int>, int>> boots(MAXN);

int numSteps, NumBoots;

bool cmp1(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
    return a.first.first > b.first.first;
}

bool cmp(int &a, int &b)
{
    return steps[a] > steps[b];
}

int main()
{
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
    fin >> numSteps >> NumBoots;

    for (int x = 0; x < numSteps; x++)
    {
        fin >> steps[x];
        before[x] = x - 1;
        after[x] = x + 1;
        indexs[x] = x;
    }

    for (int x = 0; x < NumBoots; x++)
    {
        fin >> boots[x].first.first >> boots[x].first.second;
        boots[x].second = x;
    }

    sort(boots.begin(), boots.begin() + NumBoots, cmp1);
    sort(indexs.begin(), indexs.begin() + numSteps, cmp);
    for (int x = 0; x < NumBoots; x++)
    {
        cout << boots[x].first.first << boots[x].first.second << boots[x].second << endl;
    }
    cout << endl;
    int index = 0, curMaxDepth = 1;
    vector<int> ans(MAXN);
    for (int y = 0; y < NumBoots; y++)
    {
        pair<int, int> x = boots[y].first;
        int MaxDepth = x.first, MaxStep = x.second;
        while (steps[indexs[index]] > MaxDepth && index < numSteps)
        {
            int currIndex = indexs[index];
            after[before[currIndex]] = after[currIndex];

            before[after[currIndex]] = before[currIndex];
            curMaxDepth = max(curMaxDepth, after[before[currIndex]] - before[after[currIndex]]);
            index++;
        }
        if (curMaxDepth > MaxStep)
            ans[boots[y].second] = 0;
        else
            ans[boots[y].second] = 1;
    }
    for (int x = 0; x < NumBoots; x++)
        fout << ans[x] << endl;
}