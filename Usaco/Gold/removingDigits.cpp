#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[1000001];
int num;
int solve(int currNum)
{
    if (currNum < 0)
        return -1;
    else if (currNum == 0)
        return 0;
    else if (dp[currNum] != -1)
        return dp[currNum];
    int minSteps = INT32_MAX;
    int lNum = currNum;
    while (lNum > 0)
    {
        if (lNum % 10 != 0)
        {
            int l = solve(currNum - (lNum % 10));
            if (l != -1)
                minSteps = min(minSteps, l + 1);
        }
        lNum /= 10;
    }
    dp[currNum] = minSteps;
    return minSteps;
}

int main()
{
    for (int x = 0; x < 1000001; x++)
    {
        dp[x] = -1;
    }
    cin >> num;
    cout << solve(num);
}