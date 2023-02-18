#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    char arr[n][n];
    int dp[n][n];
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            cin >> arr[x][y];
            dp[x][y] = 0;
        }
    }
    arr[0][0] == '.' ? dp[0][0] = 1 : 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (arr[x][y] != '*')
            {
                if (x != 0 && arr[x - 1][y] != '*')
                    dp[x][y] += dp[x - 1][y] %= MOD;
                if (y != 0 && arr[x][y - 1] != '*')
                    dp[x][y] += dp[x][y - 1] %= MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] % MOD << endl;
}