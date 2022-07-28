#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool taken[100001];
vector<int> Elsie, Bessie;
int main()
{
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");

    int N, ans = 0;
    fin >> N;

    for (int x = 0; x < N; x++)
    {
        int n;
        fin >> n;
        taken[n] = true;
        Elsie.push_back(n);
    }
    for (int x = 1; x <= N * 2; x++)
    {
        if (!taken[x])
        {
            Bessie.push_back(x);
        }
    }
    sort(Bessie.begin(), Bessie.end());
    int var;
    for (int x = 0; x < N; x++)
    {
        var = 0;
        if (Elsie[x] < Bessie[Bessie.size() - 1])
        {
            while (Bessie[var] < Elsie[x] && var < Bessie.size())
                var++;
            if (var != Bessie.size())
            {
                Bessie.erase(Bessie.begin() + var);
                ans++;
            }
        }
    }
    fout << ans;
}