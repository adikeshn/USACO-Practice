#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int N, D;
vector<int> coins;
int dp[1000001] = {};
long long solve(int curSum)
{
    if (curSum == 0)
    {
        return 0;
    }
    else if (curSum < 0)
    {
        return 100000000;
    }
    else if (dp[curSum] != 0)
        return dp[curSum];
    long long best = 100000000;
    for (int x : coins)
    {
        best = min(best, solve(curSum - x) + 1);
    }
    dp[curSum] = best;
    return best;
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

    long long a = solve(D);
    if (a == 100000000)
        cout << -1;
    else
        cout << a;
}