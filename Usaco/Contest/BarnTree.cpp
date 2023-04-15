#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2 * 100000 + 1;
vector<long long> graphCurr[MAXN], bales(MAXN), needed(MAXN);
vector<pair<pair<long long, long long>, long long>> steps;
vector<bool> vis(MAXN, false);
long long NeedToFind = 0, ans = 0;

long long createGraphNeeded(long long curr)
{
    vis[curr] = true;
    long long current = bales[curr];
    for (int connection : graphCurr[curr])
    {
        if (!vis[connection])
            current += createGraphNeeded(connection);
    }
    needed[curr] = current - NeedToFind;
    return current - NeedToFind;
}

void createSteps(int curr)
{
    vis[curr] = true;
    vector<long long> positives;
    vector<long long> negatives;
    for (int connection : graphCurr[curr])
    {
        if (!vis[connection])
        {
            if (needed[connection] > 0)
                positives.push_back(connection);
            else if (needed[connection] <= 0)
                negatives.push_back(connection);
        }
    }
    for (int x : positives)
    {

        createSteps(x);
        steps.push_back({{x, curr}, needed[x]});
    }
    for (int x : negatives)
    {
        if (needed[x] < 0)
            steps.push_back({{curr, x}, -needed[x]});
        createSteps(x);
    }
}

int main()
{
    int N;
    cin >> N;
    for (int x = 0; x < N; x++)
    {
        cin >> bales[x];
    }
    for (int x = 0; x < N; x++)
    {
        NeedToFind += bales[x];
    }
    NeedToFind /= N;
    for (int x = 0; x < N - 1; x++)
    {
        int a, b;
        cin >> a >> b;
        graphCurr[a - 1].push_back(b - 1);
        graphCurr[b - 1].push_back(a - 1);
    }

    createGraphNeeded(0);
    vis = vector<bool>(MAXN, false);
    createSteps(0);
    cout << steps.size() << endl;
    for (pair<pair<long long, long long>, long long> i : steps)
    {
        cout << i.first.first + 1 << " " << i.first.second + 1 << " " << i.second << endl;
    }
}