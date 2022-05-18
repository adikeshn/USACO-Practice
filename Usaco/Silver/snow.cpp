#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct boot
{
    int depth;
    int step;
};

int main()
{
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
    int N, B;
    fin >> N >> B;
    vector<int> path(N);
    vector<boot> boots(B);
    for (int x = 0; x < N; x++)
    {
        fin >> path[x];
    }
    for (int x = 0; x < B; x++)
    {
        boot n;
        fin >> n.depth >> n.step;
        boots[x] = n;
    }
    int curr = 0, currentpos = 0;
    while (currentpos != N - 1)
    {
        boot currboot = boots[curr];
        int max = -1;
        for (int x = 1; x <= currboot.step && currentpos + x < N; x++)
        {
            if (path[currentpos + x] <= currboot.depth)
                max = currentpos + x;
        }
        if (max != -1)
            currentpos = max;
        else
        {
            int m = 1;
            while (boots[curr + m].depth < path[currentpos])
            {
                m++;
            }
            curr += m;
        }
    }
    fout << curr;
}