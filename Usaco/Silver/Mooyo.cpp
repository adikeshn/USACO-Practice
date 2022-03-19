#include <iostream>
#include <fstream>
using namespace std;

int grid[101][11], N, K;

int checkValid(int i, int j, int current, int num, int vis[][11])
{
    if (grid[i][j] != num || i < 0 || i >= N || j < 0 || j >= 10 || vis[i][j] == 1)
    {
        return 0;
    }
    vis[i][j] = 1;
    current = 1;
    current += checkValid(i + 1, j, 0, num, vis);
    current += checkValid(i - 1, j, 0, num, vis);
    current += checkValid(i, j - 1, 0, num, vis);
    current += checkValid(i, j + 1, 0, num, vis);

    return current;
}

void findArea(int i, int j, int num, int vis[][11])
{
    if (grid[i][j] != num || i < 0 || i >= N || j < 0 || j >= 10)
    {
        return;
    }
    vis[i][j] = 1;
    grid[i][j] = 0;
    findArea(i + 1, j, num, vis);
    findArea(i - 1, j, num, vis);
    findArea(i, j - 1, num, vis);
    findArea(i, j + 1, num, vis);
}

void moveDown(int i, int j)
{
    int newx = i;
    while (grid[newx + 1][j] == 0 && newx + 1 < N)
        newx++;
    int n = grid[i][j];
    grid[i][j] = 0;
    grid[newx][j] = n;
}

int main()
{
    ifstream fin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");
    int answer = 0, perm = 0;
    char a;
    fin >> N >> K;
    int vis[N + 1][11];
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            fin >> a;
            grid[x][y] = (int)a - 48;
            vis[x][y] = 0;
        }
    }
    while (true)
    {
        int n = 0;
        for (int x = N - 1; x >= 0; x--)
        {
            for (int y = 0; y < 10; y++)
            {
                int b = grid[x][y];
                if (grid[x][y] != 0)
                {
                    if (checkValid(x, y, 0, grid[x][y], vis) >= K)
                    {
                        n++;
                        findArea(x, y, grid[x][y], vis);
                    }
                }
            }
        }
        if (n == 0)
            break;
        else
        {
            for (int x = N - 1; x >= 0; x--)
            {
                for (int y = 0; y < 10; y++)
                {
                    vis[x][y] = 0;
                    if (grid[x][y] != 0)
                    {
                        moveDown(x, y);
                    }
                }
            }
        }
    }
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            fout << grid[x][y];
        }
        fout << endl;
    }
}