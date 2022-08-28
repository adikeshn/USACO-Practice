#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct hoof
{
    int H = 0;
    int P = 0;
    int S = 0;
};

int main()
{
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int N;
    fin >> N;

    hoof h, prefix[100000];
    for (int x = 0; x < N; x++)
    {
        char j;
        fin >> j;
        if (j == 'H')
            h.H++;
        else if (j == 'P')
            h.P++;
        else if (j == 'S')
            h.S++;
        prefix[x] = h;
        cout << prefix[x].H << " " << prefix[x].S << " " << prefix[x].P << endl;
    }

    int answer = 0;
    hoof check = prefix[N - 1];
    for (hoof n : prefix)
    {
        int maxs = max(n.H, max(n.P, n.S)), maxn = max(check.H - n.H, max(check.P - n.P, check.S - n.S));
        answer = max(maxs + maxn, answer);
    }
    fout << answer;
}