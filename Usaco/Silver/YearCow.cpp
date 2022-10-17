#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;

vector<int> intervals;

int main()
{
    cin >> N >> K;
    vector<int> cows(N);
    for (int x = 0; x < N; x++)
    {
        cin >> cows[x];
    }
    sort(cows.begin(), cows.end());
    int currStart, prev = -12;
    for (int x : cows)
    {
        currStart = 12 * (x / 12);

        if (currStart > prev)
        {
            intervals.push_back((currStart - (prev + 12)));
        }
        prev = currStart;
    }
    int start = 12 * (cows[0] / 12), end = (12 * (cows[cows.size() - 1] / 12)) + 12, current = end;
    sort(intervals.begin(), intervals.end(), greater<int>());
    for (int x = 0; x < K - 1 && x < intervals.size(); x++)
    {
        current -= intervals[x];
    }
    cout << current;
}