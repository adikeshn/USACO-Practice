#include <iostream>
#include <algorithm>
using namespace std;

int *Sum(int ar[], int n, int K);

int main()
{
    int K, n, index = 0;
    cin >> n >> K;
    int ar[n];
    int a[3];
    bool l;
    for (int x = 0; x < n; x++)
    {
        cin >> ar[x];
    }
    int *p;
    p = Sum(ar, n, K);
    if (p != nullptr)
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < n; y++)
            {
                if (p[x] == ar[y])
                {
                    l = true;
                    for (int z : a)
                    {
                        if (z == y)
                        {
                            l = false;
                        }
                    }
                    if (l)
                    {
                        a[index] = y;
                        index++;
                        break;
                    }
                }
            }
        }
        for (int y = 0; y < 3; y++)
        {
            cout << a[y] + 1 << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

int *Sum(int na[], int n, int K)
{
    int current, p1, p2;
    static int answers[3];
    int ar[n];
    copy(na, na + n, ar);
    sort(ar, ar + n);
    for (int x = n - 1; x >= 0; x--)
    {
        current = ar[x];
        p1 = x - 1;
        p2 = 0;
        while (p1 > 0 && p2 < x - 1)
        {
            if (current + ar[p1] + ar[p2] > K)
            {
                p1--;
            }
            else if (current + ar[p1] + ar[p2] < K)
            {
                p2++;
            }
            else
            {
                answers[0] = ar[p2];
                answers[1] = ar[p1];
                answers[2] = current;
                return answers;
            }
        }
    }
    return nullptr;
}