#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    int N;
    fin >> N;
    int ar[N];
    int prefix[N + 1] = {};
    int answer = 0;
    for (int x = 0; x < N; x++)
    {
        fin >> ar[x];
        prefix[x + 1] = (ar[x] + prefix[x]) % 7;
    }
    vector<int> last(7, -1);

    for (int x = 0; x < N; x++)
    {
        if (last[prefix[x]] == -1)
        {
            last[prefix[x]] = x;
        }
        else
        {
            if (x - last[prefix[x]] > answer)
            {
                answer = x - last[prefix[x]];
            }
        }
    }
    fout << answer;
}