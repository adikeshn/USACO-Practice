#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    int N, maximum = 0, minimum = N + 2;
    fin >> N;
    vector<int> cows;
    for (int x = 0; x < N; x++)
    {
        int a;
        fin >> a;
        cows.push_back(a);
    }
    sort(cows.begin(), cows.end());
    maximum = max(cows[N - 1] - cows[1] - (N - 2), cows[N - 2] - cows[0] - (N - 2));

    int p1 = 0, p2 = 1;
    int m = cows[p1] + (N - 1);

    bool otherTest = false;

    for (int x = 1; x < N; x++)
    {
        if ((x != N - 1 && cows[x] - 1 != cows[x - 1]) || (x == N - 1 && cows[x] <= cows[x - 1] + 2))
        {
            otherTest = true;
            break;
        }
    }
    if (otherTest)
    {
        otherTest = false;
        for (int x = N - 2; x >= 0; x--)
        {
            if ((x != 0 && cows[x] + 1 != cows[x + 1]) || (x == 0 && cows[x] >= cows[x + 1] - 2))
            {
                otherTest = true;
                break;
            }
        }
    }
    if (!otherTest)
    {
        fout << 2 << endl;
        fout << maximum;
        cout << "enfef";
    }
    else
    {
        while (p1 < N)
        {
            if (p2 < N)
            {
                if (cows[p2] <= m)
                    p2++;
                else
                {
                    minimum = min(N - (p2 - p1), minimum);
                    p1++;
                    m = cows[p1] + (N - 1);
                }
            }
            else
            {
                minimum = min(N - (p2 - p1), minimum);
                p1++;
                m = cows[p1] + (N - 1);
            }
        }
        fout << minimum << endl
             << maximum;
    }
}