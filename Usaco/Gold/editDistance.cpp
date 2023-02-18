#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string i, j;
    cin >> i >> j;
    int dp[i.size()][j.size()];
    dp[0][0] = 1;
    if (i[0] == j[0])
        dp[0][0] = 0;
    for (int x = 0; x < i.size(); x++)
    {
        for (int y = 0; y < j.size(); y++)
        {
            dp[x][y] = 5001;
            if (x > 0)
            {
                dp[x][y] = min(dp[x][y], dp[x - 1][y] + 1);
            }
            if (y > 0)
                dp[x][y] = min(dp[x][y], dp[x][y - 1] + 1);
            if (x > 0 && y > 0)
            {
                if (i[x] == j[y])
                    dp[x][y] = dp[x - 1][y - 1];
                else
                    dp[x][y] = min(dp[x][y], dp[x - 1][y - 1] + 1);
            }
        }
    }
    cout << dp[i.size() - 1][j.size() - 1];
}