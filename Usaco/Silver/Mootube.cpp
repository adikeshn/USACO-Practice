#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> pairs[6001], vis(6001, 0);
int relevance[6001][6001];

int dfs(int start, long long minimum, int min)
{

    vis[start] = 1;
    int current = 0;
    for (int x : pairs[start])
    {
        if (vis[x] == 0)
        {
            int prev = min;
            if (relevance[start][x] < min || min == -1)
                min = relevance[start][x];
            if (min >= minimum)
            {
                current++;
                current += dfs(x, minimum, min);
            }
            min = prev;
        }
    }
    return current;
}

int main()
{
    ifstream fin("mootube.in");
    ofstream fout("mootube.out");
    int N, Q, b, c;
    long long a;
    fin >> N >> Q;
    for (int x = 0; x < N - 1; x++)
    {
        fin >> a >> b >> c;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
        relevance[a][b] = c;
        relevance[b][a] = c;
    }
    vector<int> temp;
    for (int x = 0; x < Q; x++)
    {
        fin >> a >> b;
        fout << dfs(b, a, -1) << endl;
        fill(vis.begin(), vis.end(), 0);
    }
}