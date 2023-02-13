#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define MAXDAY 1000
#define ll long long
int N, M, C;

int main()
{
    ifstream fin("time.in");
    ofstream fout("time.out");
    fin >> N >> M >> C;
    vector<int> costs(1000), adj[1000];
    for (int x = 0; x < N; x++)
    {
        fin >> costs[x];
    }
    for (int x = 0; x < M; x++)
    {
        int a, b;
        fin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }
    set<int> currLevel;
    currLevel.insert(0);
    ll ans = 0;
    vector<vector<ll>> dp;
    dp.resize(1000, vector<ll>(1000, -1));

    dp[0][0] = 0;
    for (int curDay = 1; curDay < 1000; curDay++)
    {
        set<int> nextLevel;
        for (int curNode : currLevel)
        {
            for (int adjacent : adj[curNode])
            {
                dp[adjacent][curDay] = max(dp[adjacent][curDay], dp[curNode][curDay - 1] + costs[adjacent]);
                nextLevel.insert(adjacent);
            }
        }
        currLevel = nextLevel;
        ans = max(ans, dp[0][curDay] - (C * curDay * curDay));
    }
    fout << ans;
}