#include <iostream>
using namespace std;

int findWidestMountain(int n, int arr[])
{
    int maxl = 0;
    for (int x = 0; x < n; x++)
    {
        int nl = 1;
        int prev = arr[x];
        bool increase = true;
        for (int y = x + 1; y < n; y++)
        {
            if (increase && arr[y] > prev)
            {
                prev = arr[y];
                nl++;
            }
            else if (increase && nl > 1 && arr[y] < prev)
            {
                prev = arr[y];
                increase = false;
                nl++;
            }
            else if (!increase && arr[y] < prev)
            {
                prev = arr[y];
                increase = false;
                nl++;
            }
            else
            {
                break;
            }
        }
        if (nl > maxl && !increase)
        {
            maxl = nl;
        }
    }
    return maxl;
}

// Do not modify below this line
int main()
{
    int t;
    cin >> t;

    while (t > 0)
    {
        t--;
        int n;
        int x;
        cin >> n;
        int array[n];

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            array[i] = x;
        }

        cout << findWidestMountain(n, array) << endl;
    }
}