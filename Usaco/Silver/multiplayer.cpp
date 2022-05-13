#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int grid[250][250];
bool vis[250][250] = {false};
int N;
int dfs(int x, int y)
{
    int count = 1;
    vis[x][y] = true;
    if (x != 0)
    {
        if (grid[x - 1][y] == grid[x][y] && !vis[x - 1][y])
            count += dfs(x - 1, y);
    }
    if (x < N)
    {
        if (grid[x + 1][y] == grid[x][y] && !vis[x + 1][y])
            count += dfs(x + 1, y);
    }
    if (y != 0)
    {
        if (grid[x][y - 1] == grid[x][y] && !vis[x][y - 1])
            count += dfs(x, y - 1);
    }
    if (y < N)
    {
        if (grid[x][y + 1] == grid[x][y] && !vis[x][y + 1])
            count += dfs(x, y + 1);
    }
    return count;
}

int dfs2(int x, int y, int c1, int c2, bool vis2[][250])
{
    int count = 1;
    vis2[x][y] = true;
    if (x != 0)
    {
        if ((grid[x - 1][y] == c1 || grid[x - 1][y] == c2) && !vis2[x - 1][y])
            count += dfs2(x - 1, y, c1, c2, vis2);
    }
    if (x < N)
    {
        if ((grid[x + 1][y] == c1 || grid[x + 1][y] == c2) && !vis2[x + 1][y])
            count += dfs2(x + 1, y, c1, c2, vis2);
    }
    if (y != 0)
    {
        if ((grid[x][y - 1] == c1 || grid[x][y - 1] == c2) && !vis2[x][y - 1])
            count += dfs2(x, y - 1, c1, c2, vis2);
    }
    if (y < N)
    {
        if ((grid[x][y + 1] == c1 || grid[x][y + 1] == c2) && !vis2[x][y + 1])
            count += dfs2(x, y + 1, c1, c2, vis2);
    }
    return count;
}

int main()
{
    ifstream fin("multimoo.in");
    ofstream fout("multimoo.out");
    vector<int> players;
    fin >> N;

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            fin >> grid[x][y];
            if (count(players.begin(), players.end(), grid[x][y]) == 0)
            {
                players.push_back(grid[x][y]);
            }
        }
    }
    bool vis2[250][250] = {false};
    int max = 0;
    int max2 = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            int n = dfs(x, y);
            int p = 0, h = 0;
            if (x < N)
            {
                if (grid[x][y] != grid[x + 1][y])
                    p = dfs2(x, y, grid[x][y], grid[x + 1][y], vis2);
            }
            if (y < N)
            {
                if (grid[x][y] != grid[x][y + 1])
                    h = dfs2(x, y, grid[x][y], grid[x][y + 1], vis2);
            }

            if (h > max2)
                max2 = h;
            if (p > max2)
                max2 = p;
            if (n > max)
            {
                max = n;
            }
        }
    }

    fout << max << endl
         << max2;
}