#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
vector<pair<ll, ll>> points;
int N;

ll findArea(ll maxx, ll minx, ll maxy, ll miny)
{
    return (maxx - minx) * (maxy - miny);
}

ll findMaxDiff()
{
    vector<ll> areaAtEach;
    ll maxx = points[0].first, minx = points[0].first, maxy = points[0].second, miny = points[0].second;
    for (pair<ll, ll> x : points)
    {
        maxx = max(maxx, x.first);
        minx = min(minx, x.first);
        maxy = max(maxy, x.second);
        miny = min(miny, x.second);

        areaAtEach.push_back(findArea(maxx, minx, maxy, miny));
    }
    maxx = points[points.size() - 1].first,
    minx = points[points.size() - 1].first,
    maxy = points[points.size() - 1].second,
    miny = points[points.size() - 1].second;
    ll maxArea = areaAtEach[N - 1], ans = 0;
    for (int y = points.size() - 1; y >= 1; y--)
    {
        pair<ll, ll> x = points[y];
        maxx = max(maxx, x.first);
        minx = min(minx, x.first);
        maxy = max(maxy, x.second);
        miny = min(miny, x.second);
        ans = max(ans, maxArea - (findArea(maxx, minx, maxy, miny) + areaAtEach[y - 1]));
    }
    return ans;
}

int main()
{
    ifstream fin("split.in");
    ofstream fout("split.out");
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        ll a, b;
        fin >> a >> b;
        points.push_back({a, b});
    }
    ll ans = 0;
    sort(points.begin(), points.end());
    ans = max(ans, findMaxDiff());
    cout << ans << endl;
    sort(points.begin(), points.end(), [](pair<ll, ll> &left, pair<ll, ll> &right)
         { return left.second < right.second; });
    ans = max(ans, findMaxDiff());
    fout << ans;
}