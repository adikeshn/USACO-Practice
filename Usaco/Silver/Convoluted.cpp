#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, M, line[10010] = {0};
bool containStarts[5001] = {false}, containEnds[5001] = {false};
unordered_map<int, int> starts, ending;

int main()
{
    cin >> N >> M;
    for (int x = 0; x < N; x++)
    {
        int s, e;
        cin >> s >> e;
        if (!containStarts[s])
            starts[s] = 1;
        else
            starts[s]++;

        if (!containEnds[e])
            ending[e] = 1;
        else
            ending[e]++;
        containStarts[s] = true;
        containEnds[e] = true;
    }
    for (const auto &[key, value] : starts)
    {
        for (const auto &[key1, value1] : starts)
        {
            line[key + key1] += value * value1;
        }
    }
    for (const auto &[key, value] : ending)
    {
        for (const auto &[key1, value1] : ending)
        {
            line[key1 + key + 1] -= value1 * value;
        }
    }
    long long ans = 0;
    for (int x = 0; x < 2 * M + 1; x++)
    {
        ans += line[x];
        cout << ans << endl;
    }
}