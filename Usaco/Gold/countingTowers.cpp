#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int T;
ll MOD = 1e9 + 7;
// 0: can extend either or non
// 1: can only extend all or non

int main()
{
    int N = 1000000;
    ll dp[1000002][2];
    dp[N + 1][0] = 1;
    dp[N + 1][1] = 1;
    for (int x = N; x >= 2; x--)
    {

        dp[x][0] = ((dp[x + 1][1] + dp[x + 1][0]) % MOD) + (dp[x + 1][0] % MOD) + (2 * dp[x + 1][0] % MOD);
        dp[x][1] = ((dp[x + 1][1] + dp[x + 1][0]) % MOD) + (dp[x + 1][1] % MOD);
    }
    cin >> T;
    for (int x = 0; x < T; x++)
    {
        int n;
        cin >> n;
        cout << (dp[N - n + 2][0] + dp[N - n + 2][1]) % MOD << endl;
    }
}