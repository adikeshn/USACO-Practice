#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("herding.in");
    ofstream fout("herding.out");
    int N, min = 0;
    fin >> N;
    int max = N - 1;
    int cows[N];
    for (int x = 0; x < N; x++)
    {
        fin >> cows[x];
    }
    int curr = 0;
    sort(cows, cows + N);
    if (cows[N - 1] - cows[1] > cows[N - 2] - cows[0])
    {
        min = cows[N - 1] - cows[1] - (N - 2);
    }
    else
    {
        min = cows[N - 2] - cows[0] - (N - 2);
    }
    int num_objects = 0;
    int num_zero = 0;
    for (int x = 0; x < N - 1; x++)
    {
        if (num_objects == 0 && (N - (cows[x + 1] - cows[x] - 1)) - 2 >= 0)
        {
            num_objects = 2;
            curr = cows[x + 1] - cows[x] - 1;
            if ((cows[x + 1] - cows[x] - 1) == 0)
            {
                num_zero += 2;
            }
        }
        else if (num_objects > 0 && N - ((cows[x + 1] - cows[x] - 1) + curr) - (num_objects + 1) >= 0)
        {
            num_objects++;
            curr += (cows[x + 1] - cows[x] - 1);
            if ((cows[x + 1] - cows[x] - 1) == 0)
            {
                num_zero++;
            }
        }

        else
        {
            if (num_zero == N - 1)
            {
                if (x == N)
                {
                    max = cows[N - 2] - cows[0] - (N - 2);
                }
                else
                {
                    max = cows[N - 1] - cows[1] - (N - 2);
                }
            }
            else if (N - num_objects < max)
            {
                max = N - num_objects;
            }
            curr = 0;
            num_objects = 0;
            num_zero = 0;
        }
    }
    if (num_zero == N - 1)
    {
        max = cows[N - 2] - cows[0] - (N - 2);
    }
    else if (N - num_objects < max)
    {
        max = N - num_objects;
    }
    curr = 0;
    num_objects = 0;
    curr = 0;
    num_objects = 0;
    fout << max << endl
         << min;
}