#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
#define MAXT 5000000
bool dp[MAXT][1] = {false};
int T, A, B, ans = 0;
int solve(int currSum, bool usedWater)
{
    if (currSum > T)
        return -1;
    else if (dp[currSum][usedWater])
        return -1;
    ans = max(ans, currSum);
    if (!usedWater)
    {
        solve(currSum + A, false);
        solve(currSum + B, false);
        solve(currSum / 2, true);
    }
    else
    {
        solve(currSum + A, true);
        solve(currSum + B, true);
    }
    dp[currSum][usedWater] = true;
}
int main()
{
    ifstream fin("feast.in");
    ofstream fout("feast.out");

    fin >> T >> A >> B;
    solve(0, false);
    fout << ans;
}
