#include <iostream>
#include <fstream>
using namespace std;

char grid[20][20];
int N;

void check(int i, int j, int l, int m, char word1, char word2)
{
}

string find(int x, int y, int z, int m)
{
    char one = '.', two = '.', three = '.';
    string word;
    for (int b = x; b < z; b++)
    {
        for (int n = y; n < m; n++)
        {
            if (one == '.')
            {
                one = grid[b][n];
            }
            else if (two == '.' && grid[b][n] != one)
            {
                two = grid[b][n];
            }
            else if (three == '.' && grid[b][n] != two)
            {
                return ".";
            }
        }
    }
    word[0] = one;
    word[1] = two;
    return word;
}

int main()
{
    ifstream fin("where.in");
    ofstream fout("where.out");
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
            for (int z = x; z < N; z++)
            {
                for (int m = y; m < N; m++)
                {
                    string n = find(x, y, z, m);
                    if (n[0] != '.')
                    {
                        cout << n << endl;
                    }
                }
            }
        }
    }
}