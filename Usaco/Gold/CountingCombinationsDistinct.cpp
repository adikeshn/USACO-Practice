#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int N, D;
vector<int> coins;
long long dp[1000001][100] = {};
bool ready[1000001][100] = {false};
long long solve(int curSum, int curMax)
{
    if (curSum == D)
        return 1;
    else if (curSum > D)
        return 0;
    else if (curMax >= N)
        return 0;
    else if (ready[curSum][curMax])
        return dp[curSum][curMax];

    long long count = 0;
    count += solve(curSum + coins[curMax], curMax) + solve(curSum, curMax + 1);
    dp[curSum][curMax] = count;
    ready[curSum][curMax] = true;
    return count;
}

int main()
{
    cin >> N >> D;
    for (int x = 0; x < N; x++)
    {
        int a;
        cin >> a;
        coins.push_back(a);
    }
    sort(coins.begin(), coins.end());
    long long a = solve(0, 0) % 1000000007;
    cout << a;
}