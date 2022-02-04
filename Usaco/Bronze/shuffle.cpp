#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int N;
    fin >> N;
    int shuffle[N];
    int current[N];
    for (int x = 0; x < N; x++)
    {
        int z;
        fin >> z;
        shuffle[z - 1] = x + 1;
    }
    for (int x = 0; x < N; x++)
    {
        fin >> current[x];
    }

    for (int x = 0; x < 3; x++)
    {
        int ar[N];
        for (int y = 0; y < N; y++)
        {
            ar[shuffle[y] - 1] = current[y];
        }
        for (int y = 0; y < N; y++)
        {
            current[y] = ar[y];
        }
    }
    for (int x = 0; x < N; x++)
    {
        fout << current[x] << endl;
    }
}
