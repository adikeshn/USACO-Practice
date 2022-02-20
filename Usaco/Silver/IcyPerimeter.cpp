#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N;
char grid[1000][1000];

int findArea(int i, int j, int current)
{
    if (grid[i][j] == '.' || grid[i][j] == ',' || i < 0 || i >= N || j < 0 || j >= N)
    {
        return 0;
    }
    current = 1;
    grid[i][j] = ',';
    current += findArea(i + 1, j, 0);
    current += findArea(i - 1, j, 0);
    current += findArea(i, j - 1, 0);
    current += findArea(i, j + 1, 0);

    return current;
}

int findPerimeter(int i, int j, int current)
{
    if (grid[i][j] == '.' || grid[i][j] == 'm' || i < 0 || i >= N || j < 0 || j >= N)
    {
        return 0;
    }
    grid[i][j] = 'm';
    if (i + 1 < N)
    {
        if (grid[i + 1][j] == '.')
        {
            current++;
        }
    }
    else
    {
        current++;
    }
    if (i - 1 >= 0)
    {
        if (grid[i - 1][j] == '.')
        {
            current++;
        }
    }
    else
    {
        current++;
    }
    if (j + 1 < N)
    {
        if (grid[i][j + 1] == '.')
        {
            current++;
        }
    }
    else
    {
        current++;
    }
    if (j - 1 >= 0)
    {
        if (grid[i][j - 1] == '.')
        {
            current++;
        }
    }
    else
    {
        current++;
    }

    current += findPerimeter(i + 1, j, 0);
    current += findPerimeter(i - 1, j, 0);
    current += findPerimeter(i, j - 1, 0);
    current += findPerimeter(i, j + 1, 0);

    return current;
}

int main()
{
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");
    int answer = 0, perm = 0;
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            fin >> grid[x][y];
        }
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (grid[x][y] == '#')
            {
                int a = findArea(x, y, 0);
                if (a > answer)
                {
                    answer = a;
                    perm = findPerimeter(x, y, 0);
                }
                else if (a == answer)
                {
                    perm = min(perm, findPerimeter(x, y, 0));
                }
            }
        }
    }
    fout << answer << " " << perm;
}