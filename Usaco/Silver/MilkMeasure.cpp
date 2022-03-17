#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N, G;
int compare(const void *a, const void *b)
{
    int x1 = *(const int *)a;
    int x2 = *(const int *)b;
    if (x1 > x2)
        return 1;
    if (x1 < x2)
        return -1;
    return 0;
}

int main()
{
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");

    int answer = 0;
    fin >> N >> G;
    int cows[N][3];
    vector<int> maxs;
    map<int, int> count;
    for (int x = 1; x < N + 1; x++)
    {
        count[x] = G;
    }
    for (int x = 0; x < N; x++)
    {
        int a, b, c;
        fin >> cows[x][0] >> cows[x][1] >> cows[x][2];
    }

    qsort(cows, N, sizeof(*cows), compare);

    for (int x = 0; x < N; x++)
    {
        count[cows[x][1]] += cows[x][2];
        vector<int> n = check();
    }
    cout << answer;
    fout << answer;
}