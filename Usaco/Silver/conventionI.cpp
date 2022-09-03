#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

int N, M, C;
vector<int> cows;

int checkValid(int currentTime)
{
    int currBus = 1, currFirst = 0, currEnd = 0, currCount = 0;
    currFirst = cows[0];
    for (int x = 0; x < cows.size(); x++)
    {
        if (cows[x] - currFirst > currentTime || currCount == C)
        {
            currCount = 0;
            currFirst = cows[x];
            currBus++;
        }
        currCount++;
    }
    return currBus;
}

int main()
{
    ifstream fin("convention.in");
    ofstream fout("convention.out");
    fin >> N >> M >> C;

    for (int x = 0; x < N; x++)
    {
        int a;
        fin >> a;
        cows.push_back(a);
    }

    sort(cows.begin(), cows.end());

    int currentTime = 0;

    int L = 0, R = cows[cows.size() - 1], mid;
    while (L <= R)
    {
        mid = L + ((R - L) / 2);
        int bus = checkValid(mid);
        if (bus > M)
        {
            L = mid + 1;
        }
        else if (bus <= M)
        {
            R = mid - 1;
        }
    }
    fout << mid;
}