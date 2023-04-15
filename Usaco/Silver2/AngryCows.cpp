#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int N, K;
vector<ll> cows;

bool check(ll curr)
{
    ll start = cows[0], shoot = 1;
    for (int x = 1; x < N; x++)
    {

        if (cows[x] - start > curr * 2)
        {
            start = cows[x];
            shoot++;
            if (shoot > K)
                return false;
        }
    }
    if (shoot <= K)
        return true;
}

int main()
{
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    fin >> N >> K;
    for (int x = 0; x < N; x++)
    {
        ll a;
        fin >> a;
        cows.push_back(a);
    }
    sort(cows.begin(), cows.end());
    ll L = 1, R = cows[cows.size() - 1], mid, ans = cows[cows.size() - 1];
    while (L <= R)
    {
        mid = L + ((R - L) / 2);
        if (check(mid))
        {
            R = mid - 1;
            ans = min(ans, mid);
        }
        else
            L = mid + 1;
    }
    fout << ans;
}