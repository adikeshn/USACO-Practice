#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int MAX_N = 100001, N, M;

int main()
{
    ifstream fin("cereal.in");
    ofstream fout("cereal.out");
    fin >> N >> M;

    vector<int> taken_Cereal(MAX_N, -1);
    vector<int> ans(N);
    vector<pair<int, int>> cows(MAX_N);

    for (int x = 0; x < N; x++)
    {
        fin >> cows[x].first >> cows[x].second;
    }
    int currAns = 0;
    for (int i = N - 1; i >= 0; i--)
    {

        int currpos = cows[i].first;
        int currCow = i;

        while (true)
        {
            if (taken_Cereal[currpos] == -1)
            {
                taken_Cereal[currpos] = currCow;
                currAns++;
                break;
            }
            else if (taken_Cereal[currpos] < currCow)
            {
                break;
            }
            else
            {
                int next = taken_Cereal[currpos];
                taken_Cereal[currpos] = currCow;
                if (currpos == cows[next].second)
                    break;
                currCow = next;
                currpos = cows[currCow].second;
            }
        }
        ans[i] = currAns;
    }
    for (int x : ans)
        fout << x << endl;
}
