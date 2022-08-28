#include <iostream>
#include <algorithm>
using namespace std;

int BinarySearch(int ar[], int chosen, int R);
int FindPerfectSquare(int x);
int FirstValGreaterThan(int ar[], int chosen, int R);

int main()
{
    int input[] = {2, 3, 5, 6, 8, 10, 12, 11};
    cout << FirstValGreaterThan(input, 13, sizeof(input) / sizeof(int)) << endl;
}

int BinarySearch(int ar[], int chosen, int R)
{
    int L = 0, mid;
    cout << R;
    sort(ar, ar + R + 1);
    while (L <= R)
    {
        mid = L + ((R - L) / 2);
        if (ar[mid] == chosen)
            return mid;
        else if (ar[mid] < chosen)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return -1;
}

int FindPerfectSquare(int chosen)
{
    int ar[chosen + 1];
    for (int x = 0; x < chosen + 1; x++)
    {
        ar[x] = x;
    }
    int L = 0, R = chosen, mid;
    while (L <= R)
    {
        mid = L + ((R - L) / 2);
        if (ar[mid] * ar[mid] == chosen)
            return ar[mid];
        else if (ar[mid] * ar[mid] < chosen)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return -1;
}

int FirstValGreaterThan(int ar[], int chosen, int R)
{
    int L = 0, mid;
    sort(ar, ar + R);
    int localmin = 0;
    while (L <= R)
    {
        mid = L + ((R - L) / 2);
        if (ar[mid] > chosen)
        {
            localmin = mid;
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    return localmin;
}