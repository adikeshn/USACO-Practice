#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int grid[250][250], groups[250][250];
vector<bool> groupConnect[250 * 250];
int N;
int dfs(int x, int y, int group)
{
    int count = 1;

    groups[x][y] = group;
    if (x != 0)
    {
        if (grid[x - 1][y] == grid[x][y] && groups[x - 1][y] != group)
            count += dfs(x - 1, y, group);
    }
    if (x < N)
    {
        if (grid[x + 1][y] == grid[x][y] && groups[x + 1][y] != group)
            count += dfs(x + 1, y, group);
    }
    if (y != 0)
    {
        if (grid[x][y - 1] == grid[x][y] && groups[x][y - 1] != group)
            count += dfs(x, y - 1, group);
    }
    if (y < N)
    {
        if (grid[x][y + 1] == grid[x][y] && groups[x][y + 1] != group)
            count += dfs(x, y + 1, group);
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
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            fin >> grid[x][y];
        }
    }
    int max1 = 0;
    int max2 = 0, group = 0;
    for (int x = 0; x < 250; x++)
    {
        for (int y = 0; y < 250; y++)
        {
            groups[x][y] = -1;
        }
    }
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            int p = 0, h = 0, n = 0, l = 0, a = 0;

            if (groups[x][y] == -1)
            {
                n = dfs(x, y, group);
                group++;
            }

            bool vis2[250][250] = {false};
            if (x < N - 1)
            {
                if (groups[x + 1][y] == -1)
                {
                    l = dfs(x + 1, y, group);
                    group++;
                }
                if (groups[x][y] != groups[x + 1][y] && find(groupConnect[groups[x][y]].begin(),
                                                             groupConnect[groups[x][y]].end(), groups[x + 1][y]) == groupConnect[groups[x][y]].end())
                {
                    p = dfs2(x, y, grid[x][y], grid[x + 1][y], vis2);
                    groupConnect[groups[x][y]].push_back(groups[x + 1][y]);
                    groupConnect[groups[x + 1][y]].push_back(groups[x][y]);
                }
            }
            bool vis3[250][250] = {false};
            if (y < N - 1)
            {
                if (groups[x][y + 1] == -1)
                {
                    a = dfs(x, y + 1, group);
                    group++;
                }
                if (groups[x][y] != groups[x][y + 1] && find(groupConnect[groups[x][y]].begin(),
                                                             groupConnect[groups[x][y]].end(), groups[x][y + 1]) == groupConnect[groups[x][y]].end())
                {
                    h = dfs2(x, y, grid[x][y], grid[x][y + 1], vis3);
                    groupConnect[groups[x][y]].push_back(groups[x][y + 1]);
                    groupConnect[groups[x][y + 1]].push_back(groups[x][y]);
                }
            }
            if (h > max2)
                max2 = h;
            if (p > max2)
                max2 = p;
            max1 = max(max1, max(a, max(l, n)));
            cout << group << " ";
        }
    }
    fout << max1 << endl
         << max2;
}