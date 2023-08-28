#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int N, TargetVal;

int main()
{
    cin >> N;
    vector<int> nums(N);
    int dp[2 * 100001] = {}, ans = 0;
    int minValue[2 * 100001] = {};
    for (int x = 0; x < N; x++)
    {
        cin >> nums[x];
        dp[x] = 1;
        minValue[x] = INT32_MAX;
    }
    minValue[N] = INT32_MAX;
    for (int x = 0; x < N; x++)
    {
        int added = 0;
        int L = 1, R = N, mid;
        while (L <= R)
        {
            mid = L + ((R - L) / 2);
            if (minValue[mid] < nums[x])
            {
                L = mid + 1;
                added = mid;
            }
            else
                R = mid - 1;
        }

        dp[x] += added;
        ans = max(ans, dp[x]);
        minValue[dp[x]] = min(minValue[dp[x]], nums[x]);
    }

    cout << ans;
}