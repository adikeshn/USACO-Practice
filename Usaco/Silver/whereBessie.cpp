#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int x1, x2, y1, y2;
int grid[20][20];
bool vis[20][20] = {false};
vector<int> connected(26, 0);
vector<pair<pair<int, int>, pair<int, int>>> PCL;

void floodFill(int x, int y)
{
    if (x < x1 || x > x2 || y < y1 || y > y2 || vis[x][y])
        return;
    vis[x][y] = true;
    floodFill(x + 1, y);
    floodFill(x - 1, y);
    floodFill(x, y + 1);
    floodFill(x, y - 1);
}

int main()
{
    int N;
    cin >> N;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> grid[x][y];
        }
    }

    for (x1 = 0; x1 < N; x1++)
    {
        for (y1 = 0; y1 < N; y1++)
        {
            for (x2 = x1; x2 < N; x2++)
            {
                for (y2 = y1; y2 < N; y2++)
                {
                    for (int x = x1; x < x2; x++)
                    {
                        for (int y = y1; y < y2; y++)
                        {
                            if (!vis[x][y])
                            {
                                connected[grid[x][y] - 65]++;
                                floodFill(x, y);
                            }
                        }
                    }
                    int l = 0, m = 0;
                    for (int x : connected)
                    {
                        if (x == 1)
                            l++;
                        if (x == 2)
                            m++;
                    }
                    if (l == 1 && m == 1)
                    {
                        PCL.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
                    }
                    connected = vector<int>(26, 0);
                    for (int x = 0; x < N; x++)
                    {
                        for (int y = 0; y < N; y++)
                        {
                            vis[x][y] = false;
                        }
                    }
                }
            }
        }
    }
    int PCLs = 0;
    for (pair<pair<int, int>, pair<int, int>> first : PCL)
    {
        for (pair<pair<int, int>, pair<int, int>> second : PCL)
        {
            if (!(first.first.first <= second.first.first && first.first.second <= second.first.second && first.second.second >= second.second.second && first.second.first >= second.second.first))
            {
                PCLs++;
            }
        }
    }
    cout << PCLs;
}