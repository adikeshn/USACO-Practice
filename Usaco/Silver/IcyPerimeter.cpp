#include <iostream>
#include <fstream>
using namespace std;

int N;

int findArea(int i, int j, char grid[][N], int current)
{
}

int main()
{
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    fin >> N;
    char grid[N][N];
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
                findArea(x, y, grid, 0);
            }
        }
    }
}