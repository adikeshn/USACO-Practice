#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int cows[101][2], grid[101][101], vis[101][101];
vector<int> connections[10001];

bool dfs(int x1, int y1, int x2, int y2)
{
    bool found = false;
    if (x1 == x2 && y1 == y2)
    {
        return true;
    }
    else
    {
        vis[x1][y1] = 1;
        if (x1 + 1 <= N && found == false && vis[x1 + 1][y1] == 0 && find(connections[grid[x1][y1]].begin(), connections[grid[x1][y1]].end(), grid[x1 + 1][y1]) == connections[grid[x1][y1]].end())
        {
            found = dfs(x1 + 1, y1, x2, y2);
        }
        if (x1 - 1 > 0 && found == false && vis[x1 - 1][y1] == 0 && find(connections[grid[x1][y1]].begin(), connections[grid[x1][y1]].end(), grid[x1 - 1][y1]) == connections[grid[x1][y1]].end())
        {
            found = dfs(x1 - 1, y1, x2, y2);
        }
        if (y1 + 1 <= N && found == false && vis[x1][y1 + 1] == 0 && find(connections[grid[x1][y1]].begin(), connections[grid[x1][y1]].end(), grid[x1][y1 + 1]) == connections[grid[x1][y1]].end())
        {
            found = dfs(x1, y1 + 1, x2, y2);
        }
        if (y1 - 1 > 0 && found == false && vis[x1][y1 - 1] == 0 && find(connections[grid[x1][y1]].begin(), connections[grid[x1][y1]].end(), grid[x1][y1 - 1]) == connections[grid[x1][y1]].end())
        {
            found = dfs(x1, y1 - 1, x2, y2);
        }
    }
    return found;
}

int main()
{
    ifstream fin("countcross.in");
    ofstream fout("countcross.out");

    int K, R, answer = 0, i = 1;
    fin >> N >> K >> R;

    for (int x = 1; x < N + 1; x++)
    {
        for (int y = 1; y < N + 1; y++)
        {
            grid[x][y] = i;
            i++;
        }
    }

    for (int x = 0; x < R; x++)
    {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        connections[grid[a][b]].push_back(grid[c][d]);
        connections[grid[c][d]].push_back(grid[a][b]);
        cout << grid[a][b] << " " << grid[c][d] << endl;
    }

    for (int x = 0; x < K; x++)
    {
        fin >> cows[x][0] >> cows[x][1];
    }

    for (int x = 0; x < K; x++)
    {
        for (int y = x + 1; y < K; y++)
        {
            for (int z = 1; z < N + 1; z++)
            {
                for (int v = 1; v < N + 1; v++)
                {
                    vis[z][v] = 0;
                }
            }
            if (dfs(cows[x][0], cows[x][1], cows[y][0], cows[y][1]) == false)
            {
                answer++;
            }
        }
    }
    fout << answer;
    cout << answer;
}