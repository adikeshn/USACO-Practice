#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int numBooks, TargetVal;

int main()
{
    cin >> numBooks >> TargetVal;
    vector<int> pages(numBooks), price(numBooks);
    for (int x = 0; x < numBooks; x++)
    {
        cin >> price[x];
    }
    for (int x = 0; x < numBooks; x++)
    {
        cin >> pages[x];
    }
    vector<int> currLevel(TargetVal + 1, 0);
    for (int currBook = 0; currBook < numBooks; currBook++)
    {
        vector<int> newLevel(TargetVal + 1);
        for (int prevBest = 0; prevBest < TargetVal + 1; prevBest++)
        {
            if (prevBest - price[currBook] < 0)
                newLevel[prevBest] = currLevel[prevBest];
            else
                newLevel[prevBest] = max(currLevel[prevBest], currLevel[prevBest - price[currBook]] + pages[currBook]);
        }
        currLevel = newLevel;
    }
    cout << currLevel[TargetVal];
}