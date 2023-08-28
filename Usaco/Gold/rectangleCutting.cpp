#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int N, D;
int dp[501][501] = {};
int solve(int Width, int Length)
{
    if (Width == Length)
        return 0;
    else if (dp[Width][Length] != -1)
        return dp[Width][Length];
    int minMoves = INT32_MAX;
    for (int x = 1; x <= Width / 2; x++)
    {
        minMoves = min(minMoves, solve(x, Length) + solve(Width - x, Length) + 1);
    }
    for (int x = 1; x <= Length / 2; x++)
    {
        minMoves = min(minMoves, solve(Width, x) + solve(Width, Length - x) + 1);
    }
    dp[Width][Length] = minMoves;
    return minMoves;
}

int main()
{
    cin >> N >> D;
    for (int x = 0; x < 501; x++)
    {
        for (int y = 0; y < 501; y++)
        {
            dp[x][y] = -1;
        }
    }
    long long a = solve(N, D);
    cout << a << endl;
}