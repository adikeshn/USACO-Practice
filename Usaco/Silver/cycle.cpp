#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool vis[100] = {false};

int main()
{
    ifstream fin("input.in");
    int N, M;
    cin >> N >> M;
    vector<int> graph[N];
    for (int x = 0; x < M; x++)
    {
        int i, m;
        cin >> i >> m;
        graph[i - 1].push_back(m);
    }
    for (int x = 0; x < N; x++)
    {
        if (!vis[x])
        {
        }
    }
}