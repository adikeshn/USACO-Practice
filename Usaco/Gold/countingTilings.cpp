#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
#define ll long long
ll N, M;
ll MOD = 1e9 + 7;
ll dp[1025][1002] = {}; // bitMask, row
vector<ll> currPossible;

void findPossible(int bitMask, int currBit, int currentBit)
{
    if (currentBit == N)
    {
        currPossible.push_back(currBit);
        return;
    };

    if ((bitMask & (1 << currentBit)) == 0)
    {
        findPossible(bitMask, currBit | (1 << currentBit), currentBit + 1);
        if (currentBit != N - 1 && (bitMask & (1 << (currentBit + 1))) == 0)
        {
            findPossible(bitMask, currBit, currentBit + 2);
        }
    }
    else
    {
        findPossible(bitMask, currBit, currentBit + 1);
    }
}

int main()
{

    cin >> N >> M;
    ll maxBit = pow(2, N);
    dp[0][M] = 1;
    for (int x = M - 1; x >= 0; x--)
    {
        for (int y = 0; y <= maxBit; y++)
        {
            findPossible(y, 0, 0);
            for (int z : currPossible)
            {
                dp[y][x] += dp[z][x + 1] % MOD;
            }
            currPossible = vector<ll>();
        }
    }
    cout << dp[0][0] % MOD;
}
