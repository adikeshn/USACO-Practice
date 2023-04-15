#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long dp[100001][101];
int N, M;
int MOD = 1e9 + 7;
vector<int> nums;

long long solve(int currPosition, int currValue)
{

    if (currPosition == N)
        return 1;
    else if (dp[currPosition][currValue] != -1)
        return dp[currPosition][currValue] % MOD;
    else if (currPosition != N - 1 && nums[currPosition + 1] != 0 && (nums[currPosition + 1] > currValue + 1 || nums[currPosition + 1] < currValue - 1))
        return 0;
    long long amount = 0;
    if (currPosition != N - 1 && nums[currPosition + 1] == 0)
    {
        for (int x = max(currValue - 1, 1); x <= min(currValue + 1, M); x++)
        {
            amount += solve(currPosition + 1, x) % MOD;
        }
    }
    else
        amount += solve(currPosition + 1, nums[currPosition + 1]) % MOD;

    dp[currPosition][currValue] = amount % MOD;
    return amount;
}

int main()
{
    cin >> N >> M;
    for (int x = 0; x < 100001; x++)
    {
        for (int y = 0; y < 101; y++)
        {
            dp[x][y] = -1;
        }
    }
    for (int x = 0; x < N; x++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }
    nums.push_back(-1);
    long long amount = 0;
    if (nums[0] == 0)
    {
        for (int x = 1; x <= M; x++)
        {
            amount += solve(0, x) % MOD;
        }
    }
    else
        amount = solve(0, nums[0]) % MOD;
    cout << amount % MOD;
}