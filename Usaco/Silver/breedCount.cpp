#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int N, Q;
    fin >> N >> Q;
    int next[N][3];
    int ar[N];
    for (int x = 0; x < N; x++)
    {
        fin >> ar[x];
        if (x != 0)
        {
            copy(next[x - 1], next[x - 1] + 3, next[x]);
            next[x][ar[x] - 1] += 1;
        }
        else
        {
            next[x][0] = 0;
            next[x][1] = 0;
            next[x][2] = 0;
            next[x][ar[x] - 1] += 1;
        }
    }

    for (int x = 0; x < Q; x++)
    {

        int qu[2];
        fin >> qu[0] >> qu[1];

        if (qu[0] == 1)
        {
            fout << next[qu[1] - 1][0] << " " << next[qu[1] - 1][1] << " " << next[qu[1] - 1][2];
        }
        else
        {
            int answer[3];
            answer[0] = next[qu[1] - 1][0] - next[qu[0] - 2][0];
            answer[1] = next[qu[1] - 1][1] - next[qu[0] - 2][1];
            answer[2] = next[qu[1] - 1][2] - next[qu[0] - 2][2];
            fout << answer[0] << " " << answer[1] << " " << answer[2];
        }

        if (x != Q - 1)
        {
            fout << endl;
        }
    }
}