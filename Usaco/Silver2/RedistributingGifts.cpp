#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int N;
vector<int> graph[501];
vector<int> keys[501];
vector<int> currBest(501);
bool reachable[501][501] = {false};

bool find_reachable(int curr, int start)
{
    reachable[start][curr] = true;
    for (int x : graph[curr])
    {
        if (!reachable[start][x])
            find_reachable(x, start);
    }
}

int main()
{
    cin >> N;
    for (int x = 1; x <= N; x++)
    {

        for (int y = 0; y < N; y++)
        {
            int b;
            cin >> b;
            if (b == x)
                currBest[x] = y;
            keys[x].push_back(b);
        }
    }

    for (int x = 1; x <= N; x++)
    {
        for (int y = 0; y <= currBest[x]; y++)
        {
            graph[x].push_back(keys[x][y]);
        }
    }

    for (int x = 1; x <= N; x++)
    {
        find_reachable(x, x);
    }
    for (int x = 1; x <= N; x++)
    {
        for (int y = 0; y <= currBest[x]; y++)
        {
            if (reachable[keys[x][y]][x])
            {
                cout << keys[x][y] << endl;
                break;
            }
        }
    }
}