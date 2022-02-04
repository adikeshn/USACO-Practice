#include <iostream>
#include <algorithm>
#include <stdint.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cows[n];
    int stalls[n];
    for (int x = 0; x < n; x++)
    {
        cin >> cows[x];
    }
    for (int x = 0; x < n; x++)
    {
        cin >> stalls[x];
    }
    long long mult = 1;
    int substract = 0;
    sort(cows, cows + n, greater<int>());
    for (int x : cows)
    {
        int count = 0;
        for (int y : stalls)
        {
            if (y >= x)
            {
                count += 1;
            }
        }
        mult *= count - substract;
        substract++;
    }
    cout << mult;
}