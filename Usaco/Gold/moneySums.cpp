#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, TargetVal;

int main()
{
    cin >> N;
    vector<int> nums(N);

    for (int x = 0; x < N; x++)
    {
        cin >> nums[x];
    }

    vector<bool> currLevel(1000 * 100 + 100, false);
    currLevel[0] = true;
    int num = 0;
    for (int curNum = 0; curNum < N; curNum++)
    {
        vector<bool> newLevel(1000 * 100 + 100, false);
        for (int prevBest = 0; prevBest < 1000 * 100 + 100; prevBest++)
        {
            if (nums[curNum] <= prevBest && !currLevel[prevBest])
            {
                if (currLevel[prevBest - nums[curNum]])
                {
                    num++;
                    newLevel[prevBest] = true;
                }
                else
                    newLevel[prevBest] = currLevel[prevBest];
            }
            else
                newLevel[prevBest] = currLevel[prevBest];
        }
        currLevel = newLevel;
    }
    cout << num << endl;
    for (int x = 1; x < 1000 * 100 + 100; x++)
    {
        if (currLevel[x])
            cout << x << " ";
    }
}