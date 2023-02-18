#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, TargetVal;
int MOD = 1e9 + 7;
int main()
{
    cin >> N;
    vector<int> currLevel((N * (N + 1) / 4) + 1, 0);
    currLevel[0] = 1;
    for (int x = 1; x < N; x++)
    {
        vector<int> newLevel((N * (N + 1) / 4) + 1, 0);
        for (int prevBest = 0; prevBest < (N * (N + 1) / 4) + 1; prevBest++)
        {
            newLevel[prevBest] += currLevel[prevBest];
            if (prevBest >= x)
                newLevel[prevBest] += currLevel[prevBest - x];

            newLevel[prevBest] %= MOD;
        }
        currLevel = newLevel;
    }
    if ((N * (N + 1) / 2) % 2 == 1)
        cout << 0;
    else
        cout << currLevel[(N * (N + 1) / 4)];
}