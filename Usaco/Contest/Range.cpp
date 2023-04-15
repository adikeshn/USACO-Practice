#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int N;
vector<ll> sublevels[301];
vector<ll> ans;
void solve(vector<ll> curr, int level)
{
    if (level == N - 1)
    {
        ans = curr;
        return;
    }
    vector<ll> a = curr, b = curr;
    a[level + 1] = a[level] - sublevels[level][1];
    b[level + 1] = b[level] + sublevels[level][1];
    if (a == b || level == 0)
        solve(a, level + 1);
    else
    {
        ll mina = min(a[level], a[level + 1]);
        ll maxa = max(a[level], a[level + 1]);
        ll minb = min(b[level], b[level + 1]);
        ll maxb = max(b[level], b[level + 1]);

        for (int x = level; x >= 0; x--)
        {
            mina = min(mina, a[x]);
            maxa = max(maxa, a[x]);
            minb = min(minb, b[x]);
            maxb = max(maxb, b[x]);
            if (maxa - mina != sublevels[x][level - x + 1])
            {
                solve(b, level + 1);
                break;
            }
            else if (maxb - minb != sublevels[x][level - x + 1])
            {
                solve(a, level + 1);
                break;
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N - x; y++)
        {
            int i = 0;
            cin >> i;
            sublevels[x].push_back(i);
        }
    }
    vector<ll> i(N, 0);
    solve(i, 0);
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[ans.size() - 1];
}
