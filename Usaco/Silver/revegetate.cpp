#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

int vis[100001] = {};
bool impossible = false;
void dfs(int n, vector<int> sims[], vector<int> diffs[], int y)
{
    vis[n] = y;
    for (int x : sims[n])
    {
        if (vis[x] == 0)
        {
            dfs(x, sims, diffs, y);
        }
        else if (vis[x] != y)
        {
            impossible = true;
        }
    }

    for (int x : diffs[n])
    {
        if (vis[x] == 0)
        {
            if (y == 1)
            {
                dfs(x, sims, diffs, y + 1);
            }
            else
            {
                dfs(x, sims, diffs, 1);
            }
        }
        else if (vis[x] == y)
        {
            impossible = true;
        }
    }
}

int main()
{
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    int N, M, c, b, answer = 0;
    char l;
    fin >> N >> M;
    vector<int> diffs[N + 1], sims[N + 1];
    for (int x = 0; x < M; x++)
    {
        fin >> l >> b >> c;
        if (l == 'S')
        {
            sims[b].push_back(c);
            sims[c].push_back(b);
        }
        else
        {
            diffs[b].push_back(c);
            diffs[c].push_back(b);
        }
    }

    for (int x = 0; x < N; x++)
    {
        if (vis[x + 1] == 0)
        {
            dfs(x + 1, sims, diffs, 1);
            answer += 1;
        }
    }
    if (impossible == true)
    {
        fout << "0";
    }
    else
    {
        fout << "1";
        for (int x = 0; x < answer; x++)
        {
            fout << "0";
        }
    }
}