#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct room
{
    int x;
    int y;
};

bool light[101][101] = {false}, access[101][101] = {false}, vis[101][101] = {false};
vector<room> connected[101][101];
int N;

int dfs(int x, int y, int count)
{
    count += 1;
    vis[x][y] = true;
    for (room m : connected[x][y])
    {
        light[m.x][m.y] = true;
        if (access[m.x][m.y] && !vis[m.x][m.y])
        {
            count += dfs(m.x, m.y, 0);
        }
    }
    if (x != 0)
    {
        access[x - 1][y] = true;
        if (light[x - 1][y] && !vis[x - 1][y])
            count += dfs(x - 1, y, 0);
    }
    if (y != 0)
    {
        access[x][y - 1] = true;
        if (light[x][y - 1] && !vis[x][y - 1])
            count += dfs(x, y - 1, 0);
    }
    if (x != N - 1)
    {
        access[x + 1][y] = true;
        if (light[x + 1][y] && !vis[x + 1][y])
            count += dfs(x + 1, y, 0);
    }
    if (y != N - 1)
    {
        access[x][y + 1] = true;
        if (light[x][y + 1] && !vis[x][y + 1])
            count += dfs(x, y + 1, 0);
    }
    return count;
}

int main()
{
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");
    int M;
    fin >> N >> M;
    for (int x = 0; x < M; x++)
    {
        room y;
        int b, m;
        fin >> b >> m >> y.x >> y.y;
        y.x--;
        y.y--;
        connected[b - 1][m - 1].push_back(y);
    }
    light[0][0] = true;
    access[0][0] = true;
    fout << dfs(0, 0, 0);
}