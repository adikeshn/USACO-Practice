#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;

int main()
{
    cin >> N;
    vector<pair<int, pair<int, int>>> nums(N);
    for (int x = 0; x < N; x++)
    {
        cin >> nums[x].first;

        nums[x].first--;
        nums[x].second.first = x;
        nums[x].second.second = x + 1;
    }
    vector<pair<int, pair<int, int>>> ranges;
    vector<pair<string, string>> stringVals;
    int currStart = 0, currEnd = 1;
    for (int x = 0; x < N; x++)
    {
        if (nums[x].first == nums[x + 1].first)
        {
            currEnd = nums[x + 1].second.second;
        }
        else
        {
            ranges.push_back({nums[x].first, {currStart, currEnd}});
            string Ls, Rs;
            for (int y = currStart; y < currEnd; y++)
            {
                Ls += 'L';
                Rs += 'R';
                cout << "R";
            }
            stringVals.push_back({Ls, Rs});
            if (x != N - 1)
            {
                currStart = nums[x + 1].second.first;
                currEnd = nums[x + 1].second.second;
            }
        }
    }
    int currPointer = ranges.size() - 1;
    string ans = "";
    while (ranges[0].first != 0)
    {
        int secondP = currPointer;
        string Ls = "", Rs = "";
        int val = ranges[currPointer].first;
        for (int x = currPointer; x >= 0; x--)
        {
            if (ranges[x].first > val || x == currPointer)
            {
                secondP = x;
                ranges[x].first -= val;
                Ls += stringVals[x].first;
                Rs += stringVals[x].second;
            }
            else
                break;
        }
        bool ls = true;
        for (int x = 0; x < val; x++)
        {
            if (ls)
            {
                cout << Ls;
                ls = false;
            }
            else
            {
                cout << Rs;
                ls = true;
            }
        }
        for (int x = secondP; x < currPointer; x++)
        {
            ranges[x].first--;
            cout << stringVals[x].second;
        }
        currPointer--;
    }
}
