#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ifstream fin("convention2.in");
    ofstream fout("convention2.out");
    int N;
    fin >> N;
    int cows[N][3], unsorted[N][2];
    for (int x = 0; x < N; x++)
    {
        fin >> cows[x][0] >> cows[x][1];
        unsorted[x][0] = cows[x][0];
        unsorted[x][1] = cows[x][1];
        cows[x][2] = x;
    }
    qsort(cows, N, sizeof(*cows),
          [](const void *arg1, const void *arg2) -> int
          {
              int const *lhs = static_cast<int const *>(arg1);
              int const *rhs = static_cast<int const *>(arg2);
              return (lhs[0] < rhs[0]) ? -1
                                       : ((rhs[0] < lhs[0]) ? 1
                                                            : (lhs[1] < rhs[1] ? -1
                                                                               : ((rhs[1] < lhs[1] ? 1 : 0))));
          });

    vector<int> waiting;
    vector<int> times(N, 0);
    int currenttime = 0;
    for (int x = 0; x < N; x++)
    {
        if (unsorted[x][0] == cows[0][0])
        {
            waiting.push_back(x);
        }
    }
    sort(waiting.begin(), waiting.end());
    int index = 0;
    while (index < N)
    {
        if (waiting.size() == 0)
        {
            index++;
            currenttime = cows[index][0] + cows[index][1];
            for (int x = index + 1; x < N; x++)
            {
                if (cows[x][0] <= currenttime)
                {
                    waiting.push_back(cows[x][2]);
                    index++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            for (int x = 0; x < waiting.size(); x++)
            {
                times[waiting[x]] = currenttime - unsorted[waiting[x]][0];
                if (currenttime == 0)
                {
                    times[waiting[x]] = 0;
                }
            }
            currenttime = unsorted[waiting[0]][0] + unsorted[waiting[0]][1] + times[waiting[0]];
            for (int x = index + 1; x < N; x++)
            {
                if (cows[x][0] <= currenttime)
                {
                    waiting.push_back(cows[x][2]);
                    index++;
                }
                else
                {
                    break;
                }
            }
            waiting.erase(waiting.begin());
        }
        sort(waiting.begin(), waiting.end());
    }
    fout << *max_element(times.begin(), times.end());
}
