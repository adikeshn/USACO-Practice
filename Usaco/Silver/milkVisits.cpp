#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cows[100001], vis(100001);
void dfs(int x, int group, char match[])
{
    vis[x] = group;
    for (int y : cows[x])
    {
        if (match[x - 1] == match[y - 1] && vis[y] == -1)
        {
            dfs(y, group, match);
        }
    }
}

int main()
{
    ifstream fin("milkvisits.in");
    ofstream fout("milkvisits.out");
    int N, M, a, b;
    fin >> N >> M;
    fill(vis.begin(), vis.end(), -1);
    char match[N], m;
    for (int x = 0; x < N; x++)
    {
        fin >> match[x];
    }
    for (int x = 0; x < N - 1; x++)
    {
        fin >> a >> b;
        cows[a].push_back(b);
        cows[b].push_back(a);
    }
    int group = 0;
    for (int x = 1; x < N + 1; x++)
    {
        if (vis[x] == -1)
        {
            dfs(x, group, match);
        }
        group++;
    }
    char c;
    for (int x = 0; x < M; x++)
    {
        fin >> a >> b >> c;
        if (match[a - 1] != match[b - 1])
            fout << "1";
        else
        {
            if (match[a - 1] == c)
                fout << "1";
            else
            {
                if (vis[a] != vis[b])
                    fout << "1";
                else
                    fout << "0";
            }
        }
    }
}