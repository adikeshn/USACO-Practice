#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

long long L, N, rf, rb, diff = 0;

struct stop
{
    long long x;
    long long taste;
};

bool compare(const stop &a, const stop &b)
{
    return a.x < b.x;
}

int main()
{
    ifstream fin("reststops.in");
    ofstream fout("reststops.out");
    fin >> L >> N >> rf >> rb;
    vector<stop> stops;
    stop maxs[N];
    for (int x = 0; x < N; x++)
    {
        stop temp;
        fin >> temp.x >> temp.taste;
        stops.push_back(temp);
    }
    sort(stops.begin(), stops.end(), compare);

    stop currmax = {0, 0};
    for (long long x = N - 1; x >= 0; x--)
    {
        if (stops[x].taste > currmax.taste)
            currmax = stops[x];
        maxs[x] = currmax;
    }
    long long currDistance = 0, fdistance = 0, bdistance = 0, diff = 0;
    long long answer = 0;
    stop curr = stops[0];
    for (long long x = 0; x < N; x++)
    {
        stop curr = maxs[x];
        answer += ((curr.x * rf) - ((curr.x * rb) + diff)) * curr.taste;
        diff += ((curr.x * rf) - ((curr.x * rb) + diff));
    }
    fout << answer;
}