#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int N;
ll ans = 0;
vector<pair<int, int>> points;
int above[2501][2501] = {0}, below[2501][2501] = {0};

int main()
{
    cin >> N;
    for (int x = 0; x < N; x++)
    {
        int a, b;
        cin >> a >> b;
        points.push_back({a, b});
    }
    sort(points.begin(), points.end());
    for (int x = 0; x < N; x++)
    {
        int curAbove = 0, curBelow = 0;
        for (int y = 0; y < N; y++)
        {
            if (points[y].second > points[x].second)
                curAbove++;
            else if (points[y].second < points[x].second)
                curBelow++;
            above[x][y + 1] = curAbove;
            below[x][y + 1] = curBelow;
        }
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = x + 1; y < N; y++)
        {
            int maxy = 0, miny = 0;
            if (points[x].second > points[y].second)
            {
                maxy = x;
                miny = y;
            }
            else
            {
                maxy = y;
                miny = x;
            }
            int numOnTop = above[maxy][y + 1] - above[maxy][x], numBelow = below[miny][y + 1] - below[miny][x];

            ans += (numOnTop + 1) * (numBelow + 1);
        }
    }
    cout << ans + N + 1;
}