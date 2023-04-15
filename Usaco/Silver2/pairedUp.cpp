#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

int main()
{
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");
    int N;
    map<ll, ll> nums;
    vector<ll> keys;
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        ll a, b;
        fin >> a >> b;
        nums.insert(make_pair(b, a));
    }
    for (auto x : nums)
    {
        keys.push_back(x.first);
    }
    int p1 = 0, p2 = keys.size() - 1;
    ll ans = 0;
    while (p1 <= p2)
    {
        cout << keys[p1] << " " << keys[p2] << endl;
        if (keys[p1] != keys[p2])
        {
            ll minimum = min(nums[keys[p1]], nums[keys[p2]]);
            nums[keys[p1]] -= minimum;
            nums[keys[p2]] -= minimum;
            ans = max(ans, keys[p1] + keys[p2]);
            if (nums[keys[p1]] == 0)
                p1++;
            if (nums[keys[p2]] == 0)
                p2--;
        }
        else
        {
            ans = max(ans, keys[p1] * 2);
            break;
        }
    }
    fout << ans;
}