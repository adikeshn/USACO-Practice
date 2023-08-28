#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define ll long long
ll N, Max;
vector<ll> people;
pair<ll, ll> dp[1048575 + 1]; //(rides, weights)
bool ready[1048575 + 1] = {false};
void solve(ll bitMask)
{
    if (ready[bitMask])
        return;

    ll bestRide = INT32_MAX, bestWeight = INT32_MAX, g = bitMask;
    for (int x = 0; x < N; x++)
    {
        ll currRide, currWeight;
        if ((bitMask & (1 << x)) != 0)
        {
            solve((bitMask ^ (1 << x)));

            currRide = dp[bitMask ^ (1 << x)].first;
            currWeight = dp[bitMask ^ (1 << x)].second;

            if (currWeight + people[x] > Max)
            {
                currRide++;
                currWeight = people[x];
            }
            else
            {
                currWeight += people[x];
            }

            if (currRide < bestRide)
            {
                bestWeight = currWeight;
                bestRide = currRide;
            }
            else if (currRide == bestRide)
                bestWeight = min(bestWeight, currWeight);
        }
    }

    dp[bitMask].first = bestRide;
    dp[bitMask].second = bestWeight;
    ready[bitMask] = true;
}

int main()
{
    cin >> N >> Max;
    for (int x = 0; x < N; x++)
    {
        int a;
        cin >> a;
        people.push_back(a);
    }
    dp[0] = make_pair(1, 0);
    ready[0] = true;
    solve(pow(2, N) - 1);
    cout << dp[(int)(pow(2, N) - 1)].first;
}
