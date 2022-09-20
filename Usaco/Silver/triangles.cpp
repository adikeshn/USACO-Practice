#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <math.h>
#include <numeric>
using namespace std;
struct point
{
    int val;
    long long dist;
};

void GetDistance(map<int, long long> input[])
{

    map<int, long long>::iterator itr;

    for (int i = 0; i < 20001; i++)
    {
        int size = input[i].size(), curBehind = 0, prevSum = 0;
        long long curSum = 0;
        for (itr = input[i].begin(); itr != input[i].end(); ++itr)
        {
            if (itr == input[i].begin())
            {
                curSum = std::accumulate(++input[i].begin(), input[i].end(), 0,
                                         [](auto prev_sum, auto &entry)
                                         {
                                             return prev_sum + entry.first;
                                         });
                curSum -= itr->first * (size - 1);
                itr->second = curSum;
                curBehind++;
                prevSum = itr->first;
            }
            else
            {
                int distance = abs(prevSum - itr->first);
                // curSum += (2 * curBehind - size) * (itr->first - prevSum);
                curSum = curSum + ((curBehind - 1) * distance) - ((size - 1 - curBehind) * distance);
                itr->second = curSum;
                prevSum = itr->first;
                curBehind++;
            }
        }
    }
}

map<int, long long> xDistance[20001], yDistance[20001];
vector<pair<int, int>> points;
int main()
{
    int N;
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        fin >> x >> y;
        xDistance[y + 10000].insert(pair<int, long long>(x + 10000, 0));
        yDistance[x + 10000].insert(pair<int, long long>(y + 10000, 0));
        points.push_back(pair<int, int>(x + 10000, y + 10000));
    }
    GetDistance(xDistance);
    GetDistance(yDistance);
    long long ans = 0;
    for (pair<int, int> point : points)
    {
        ans += (xDistance[point.second][point.first] * yDistance[point.first][point.second]);
    }
    fout << ans % 1000000007;
    cout << ans % 1000000007;
}