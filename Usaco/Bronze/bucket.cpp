#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int N;
    fin >> N;
    int cows[N][3];
    int times[1000] = {};

    for (int x = 0; x < N; x++)
    {
        fin >> cows[x][0];
        fin >> cows[x][1];
        fin >> cows[x][2];
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = cows[x][0] - 1; y < cows[x][1] - 1; y++)
        {
            times[y] += cows[x][2];
        }
    }

    int *answer = max_element(times, times + 1000);
    fout << *answer;
}
