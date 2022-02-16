#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int vis[100001] = {};
vector<int> ar[100001];
vector<int> connectedComps[100001];
void dfs(int n, int parent)
{
    vis[n] = 1;
    for (int x : ar[n])
    {
        if (vis[x] != 1)
        {
            connectedComps[parent].push_back(x);
            dfs(x, parent);
        }
    }
}

int main()
{
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");
    int N, M, a, b, answer = -1;
    fin >> N >> M;
    int coords[N][2];
    for (int x = 0; x < N; x++)
    {
        fin >> coords[x][0] >> coords[x][1];
    }
    for (int x = 0; x < M; x++)
    {
        fin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    for (int x = 0; x < N; x++)
    {
        if (vis[x + 1] == 0)
        {
            int x1, x2, y1, y2, area;
            dfs(x + 1, x);
            x1 = coords[x][0];
            x2 = coords[x][0];
            y1 = coords[x][1];
            y2 = coords[x][1];
            for (int y : connectedComps[x])
            {
                x1 = min(x1, coords[y - 1][0]);
                x2 = max(x2, coords[y - 1][0]);
                y1 = min(y1, coords[y - 1][1]);
                y2 = max(y2, coords[y - 1][1]);
            }
            area = ((x2 - x1) * 2) + ((y2 - y1) * 2);
            if (answer == -1 || area < answer)
            {
                answer = area;
            }
        }
    }
    fout << answer;
}