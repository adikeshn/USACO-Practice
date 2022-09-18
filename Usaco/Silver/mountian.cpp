#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
    int N;
    fin >> N;
    int answer = N;
    int points[N][2];
    int maxs[N][2];
    for (int x = 0; x < N; x++)
    {
        fin >> points[x][0] >> points[x][1];
    }

    for (int x = 0; x < N; x++)
    {
        maxs[x][0] = points[x][0] + points[x][1];
        maxs[x][1] = points[x][1] - points[x][0];
    }

    qsort(maxs, N, sizeof(*maxs),
          [](const void *arg1, const void *arg2) -> int
          {
              int const *lhs = static_cast<int const *>(arg1);
              int const *rhs = static_cast<int const *>(arg2);
              return (lhs[0] < rhs[0]) ? -1
                                       : ((rhs[0] < lhs[0]) ? 1
                                                            : (lhs[1] < rhs[1] ? -1
                                                                               : ((rhs[1] < lhs[1] ? 1 : 0))));
          });

    for (int x = N - 2; x >= 0; x--)
    {
        if (maxs[x][1] < maxs[N - 1][1])
        {
            answer--;
        }
        else
        {
            for (int y = N - 2; y > x; y--)
            {
                if (maxs[x][1] < maxs[y][1])
                {
                    answer--;
                    break;
                }
            }
        }
    }
    fout << answer;
    cout << answer;
}