#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int K, M, N;

pair<int, int> findCommonRange(pair<int, int> start, pair<int, int> end)
{
    pair<int, int> a = {max(start.first, end.first), min(start.second, end.second)};
    return a;
}

int main()
{
    vector<pair<int, int>> patches(K);
    vector<pair<int, int>> ranges(K);
    vector<int> cows(M);
    cin >> K >> M >> N;
    for (int x = 0; x < K; x++)
    {
        int a, b;
        cin >> a >> b;
        patches.push_back({a, b});
    }
    for (int x = 0; x < M; x++)
    {
        int a;
        cin >> a;
        cows.push_back(a);
    }

    sort(cows.begin(), cows.end());
    sort(patches.begin(), patches.end());

    int patchIndex = 0, cowsIndex = 0, curRange = -1000000;
    while (patchIndex < K)
    {
        if (cows[cowsIndex] < patches[patchIndex].first && cowsIndex < M)
        {
            curRange = cows[cowsIndex];
            cowsIndex++;
        }
        else if (cows[cowsIndex] > patches[patchIndex].first || cowsIndex >= M)
        {
            int x = patches[patchIndex].first + (patches[patchIndex].first - curRange);
            int y = patches[patchIndex].first - (cows[cowsIndex] - patches[patchIndex].first);
            y = max(y, 0);
            if (abs(cows[cowsIndex] - patches[patchIndex].first) < abs(curRange - patches[patchIndex].first) && cowsIndex < M)
                ranges.push_back({y, cows[cowsIndex]});
            else
                ranges.push_back({curRange, x});

            patchIndex++;
        }
        else
        {
            ranges.push_back({cows[cowsIndex], cows[cowsIndex]});
            patchIndex++;
            cowsIndex++;
        }
    }
    vector<long long> sums;
    int curCow = 0;
    long long cursum = patches[0].second;
    pair<int, int> currentRange = ranges[0];
    for (int i = 1; i < ranges.size(); i++)
    {
        pair<int, int> l = findCommonRange(currentRange, ranges[i]);
        if (l.second > l.first)
        {
            cursum += patches[i].second;
            currentRange = l;
        }
        else
        {
            if (currentRange.first != currentRange.second)
                sums.push_back(cursum);
            currentRange = ranges[i];
            cursum = patches[i].second;
        }
    }
    if (currentRange.first != currentRange.second)
        sums.push_back(cursum);
    sort(sums.begin(), sums.end());
    long long ans = 0, cur = 0;
    for (int x = sums.size() - 1; x >= 0; x--)
    {
        if (cur < N)
        {
            ans += sums[x];
            cur++;
        }
        else
            break;
    }
    cout << ans;
}