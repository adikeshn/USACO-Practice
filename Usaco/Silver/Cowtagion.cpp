#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> farms[100001];
int vis[100001] = {false};
int ans = 0;

void dfs(int currFarm, int l, int a)
{
    vis[currFarm] = true;
    ans += ceil(log2(farms[currFarm].size() + l)) + farms[currFarm].size() - a;
    for (int i : farms[currFarm])
    {
        if (farms[i].size() != 1 && !vis[i])
        {
            dfs(i, 0, 1);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int x = 0; x < N - 1; x++)
    {
        int a, b;
        cin >> a >> b;
        farms[a].push_back(b);
        farms[b].push_back(a);
    }
    dfs(1, 1, 0);
    cout << ans;
}