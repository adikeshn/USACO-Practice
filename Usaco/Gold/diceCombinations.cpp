#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long dp[1000001];
int num, MOD = 1e9 + 7;
long long solve(int currNum)
{
    if (currNum < 0)
        return 0;
    else if (currNum == 0)
        return 1;
    else if (dp[currNum] != -1)
        return dp[currNum];
    long long numCombinations = 0;
    for (int x = 1; x <= 6; x++)
    {
        numCombinations += solve(currNum - x) % MOD;
    }
    dp[currNum] = numCombinations % MOD;
    return numCombinations % MOD;
}

int main()
{
    for (int x = 0; x < 1000001; x++)
    {
        dp[x] = -1;
    }
    cin >> num;
    cout << solve(num) % MOD;
}