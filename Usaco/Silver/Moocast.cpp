#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> graph[201], vis(201);

int dfs(int n)
{
    int a = 0;
    vis[n] = 1;
    for (int x : graph[n])
    {
        if (vis[x] != 1)
        {
            a += 1;
            vis[x] = 1;
            a += dfs(x);
        }
    }
    return a;
}

float Calcdistance(int x1, int x2, int y1, int y2)
{
    return sqrt(pow(x2 - x1, 2) +
                pow(y2 - y1, 2) * 1.0);
}

int main()
{
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    int N, answer;
    fin >> N;
    int cows[N][3];
    for (int x = 0; x < N; x++)
    {
        fin >> cows[x][0] >> cows[x][1] >> cows[x][2];
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            bool isalready = false;
            for (int z : graph[x])
            {
                if (y == z)
                {
                    isalready = true;
                }
            }
            if (!isalready && y != x)
            {
                float distance = Calcdistance(cows[x][0], cows[y][0], cows[x][1], cows[y][1]);
                if (distance <= cows[x][2])
                {
                    graph[x].push_back(y);
                }
            }
        }
    }
    for (int x = 0; x < N; x++)
    {
        fill(vis.begin(), vis.end(), 0);
        answer = max(dfs(x), answer);
    }
    fout << answer + 1;
}