#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int N, D;
vector<int> coins;
long long dp[1000001] = {};
bool ready[1000001] = {false};
long long solve(int curSum)
{
    if (curSum == 0)
        return 1;
    else if (curSum < 0)
        return 0;
    else if (ready[curSum])
        return dp[curSum];
    long long count = 0;
    for (int x : coins)
    {
        count += solve(curSum - x) % 1000000007;
    }
    dp[curSum] = count;
    ready[curSum] = true;
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

    long long a = solve(D) % 1000000007;
    cout << a;
}