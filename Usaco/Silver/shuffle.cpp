#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> graph(100001);
bool vis[100001] = {false};
int detectCycle(int start)
{
    int hare = graph[graph[start]];
    int tort = graph[start];
    while (tort != hare)
    {
        if (vis[tort] || vis[hare])
            return 0;
        hare = graph[graph[hare]];
        tort = graph[tort];
    }
    tort = start;
    while (tort != hare)
    {
        if (vis[tort] || vis[hare])
            return 0;
        hare = graph[hare];
        tort = graph[tort];
    }
    tort = graph[hare];
    int length = 1;
    while (tort != hare)
    {
        vis[tort] = true;
        tort = graph[tort];
        length++;
    }
    vis[tort] = true;
    return length;
}

int main()
{
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int N;
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        int a;
        fin >> a;
        graph[x] = a - 1;
    }
    int ans = 0;
    for (int x = 0; x < N; x++)
    {
        if (vis[x] == false)
        {
            ans += detectCycle(x);
            vis[x] = true;
        }
    }
    fout << ans;
}