#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ar[N];
    for (int x = 0; x < N; x++)
    {
        cin >> ar[x];
    }
    vector<int> currentRow;
    int ans = 0;
    for (int x = 0; x < N; x++)
    {
        float currentSum = 0;
        float currentAvr = 0;
        currentRow.clear();
        for (int y = x; y < N; y++)
        {
            currentRow.push_back(ar[y]);
            currentSum += ar[y];
            currentAvr = currentSum / (y - x + 1);
            for (int z : currentRow)
            {
                if (z == currentAvr)
                {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}