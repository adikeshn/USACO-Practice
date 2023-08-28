#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int N;
ll dp[5001][5001][2] = {};
vector<ll> games;
ll solve(int start, int end, int currPlayer, int p1Points)
{
    if (start > end)
        return p1Points;
    else if (dp[start][end][currPlayer] != -1)
        return p1Points + dp[start][end][currPlayer];
    ll best;
    if (currPlayer == 0)
        best = max(solve(start + 1, end, 1, games[start]), solve(start, end - 1, 1, games[end]));
    else
        best = min(solve(start + 1, end, 0, 0), solve(start, end - 1, 0, 0));

    dp[start][end][currPlayer] = best;

    return p1Points + best;
}

int main()
{
    cin >> N;
    for (int x = 0; x < N; x++)
    {
        int a;
        cin >> a;
        games.push_back(a);
    }
    for (int x = 0; x < 5001; x++)
    {
        for (int y = 0; y < 5001; y++)
        {
            dp[x][y][0] = -1;
            dp[x][y][1] = -1;
        }
    }

    cout << solve(0, N - 1, 0, 0);
}