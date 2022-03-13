#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool checkTrue(int ar[], int max);
int N, Tmax;
int main()
{
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");

    fin >> N >> Tmax;
    int order[N];
    for (int x = 0; x < N; x++)
    {
        fin >> order[x];
    }

    int L = 1, R = N, answer;
    while (L <= R)
    {
        int mid = L + ((R - L) / 2);
        if (checkTrue(order, mid) == true)
        {
            answer = mid;
            R = mid - 1;
        }
        else
            L = mid + 1;
    }
    fout << answer;
}

bool checkTrue(int ar[], int max)
{
    vector<int> currentStage;
    int start = 0, time = 0;
    while (currentStage.size() > 0 || time == 0)
    {
        while (currentStage.size() < max)
        {
            if (start == N)
                break;
            currentStage.push_back(ar[start]);
            start++;
        }
        int min = *min_element(currentStage.begin(), currentStage.end());

        for (int x = 0; x < currentStage.size(); x++)
        {
            if (currentStage[x] - min == 0)
            {
                currentStage.erase(currentStage.begin() + x);
                x--;
            }
            else
            {
                currentStage[x] -= min;
            }
        }
        time += min;
        if (time > Tmax)
        {
            return false;
        }
    }
    return true;
}
