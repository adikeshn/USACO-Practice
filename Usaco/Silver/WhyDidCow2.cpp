#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");
    int N, K, B, currentBad, answer = 0;
    fin >> N >> K >> B;
    vector<int> walks(N, 1);
    vector<int> prefix(N + 1);
    answer = K;
    for (int x = 0; x < B; x++)
    {
        fin >> currentBad;
        walks[currentBad - 1] = 0;
    }
    for (int x = 0; x < N; x++)
    {
        if (x == 0)
        {
            prefix[x] = walks[x];
        }
        else
        {
            prefix[x] = walks[x] + prefix[x - 1];
        }
    }

    for (int x = K - 1; x < N; x++)
    {
        if (x == K - 1)
        {
            if ((K)-prefix[x] < answer)
            {
                answer = (K)-prefix[x];
            }
        }
        else
        {
            if (K - ((prefix[x] - prefix[x - (K)])) < answer)
            {
                answer = (K - (prefix[x] - prefix[x - (K)]));
            }
        }
    }
    fout << answer;
}