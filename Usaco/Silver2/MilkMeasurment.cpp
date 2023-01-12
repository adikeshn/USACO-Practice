#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    map<int, int> milkOutput, numofEach;
    vector<pair<int, pair<int, int>>> dates;
    numofEach[0] = 0;
    int N, G;
    fin >> N >> G;
    for (int x = 0; x < N; x++)
    {
        int a, b, c;
        fin >> a >> b >> c;
        if (milkOutput.find(b) == milkOutput.end())
        {
            milkOutput[b] = 0;
            numofEach[0]++;
        }
        dates.push_back({a, {b, c}});
    }
    sort(dates.begin(), dates.end());

    int curMax = 0, ans = 0;
    int NumMax = milkOutput.size();

    for (pair<int, pair<int, int>> date : dates)
    {
        int cow = date.second.first, change = date.second.second;
        bool wasMax = milkOutput[cow] == curMax;

        numofEach[milkOutput[cow]]--;
        if (numofEach[milkOutput[cow]] == 0)
            numofEach.erase(milkOutput[cow]);

        milkOutput[cow] += change;
        if (numofEach.find(milkOutput[cow]) == numofEach.end())
        {
            numofEach[milkOutput[cow]] = 0;
        }

        numofEach[milkOutput[cow]]++;

        if (wasMax)
        {

            if (NumMax > 1)
            {
                ans++;
                if (milkOutput[cow] > curMax)
                {
                    NumMax = 1;
                    curMax = milkOutput[cow];
                }
                else
                    NumMax--;
            }
            else
            {
                auto SecondPointer = --numofEach.end();

                if (milkOutput[cow] == SecondPointer->first && SecondPointer->second == 1)
                {
                    curMax = milkOutput[cow];
                }
                else
                {
                    curMax = SecondPointer->first;
                    NumMax = SecondPointer->second;
                    ans++;
                }
            }
        }
        else
        {
            if (milkOutput[cow] == curMax)
            {
                NumMax++;
                ans++;
            }
            else if (milkOutput[cow] > curMax)
            {
                curMax = milkOutput[cow];
                NumMax = 1;
                ans++;
            }
        }
        cout << curMax << NumMax << ans << endl;
    }
    fout << ans;
}