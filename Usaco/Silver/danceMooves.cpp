#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<int> locations[100001], currSet;
int connections[100001] = {0};
vector<bool> vis(100001, false);
vector<int> ans(100001, 0);

void dfs(int curr)
{
    vis[curr] = true;
    for (int x : locations[curr])
    {
        currSet.insert(x);
    }
    if (!vis[connections[curr]])
        dfs(connections[curr]);
    ans[curr - 1] = currSet.size();
}
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> order;
    for (int x = 1; x <= N; x++)
    {
        order.push_back(x);
        locations[x].insert(x);
    }
    for (int x = 0; x < K; x++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        locations[order[p1 - 1]].insert(p2);
        locations[order[p2 - 1]].insert(p1);
        swap(order[p1 - 1], order[p2 - 1]);
    }
    for (int x = 0; x < N; x++)
    {
        connections[order[x]] = x + 1;
    }
    for (int x = 1; x <= N; x++)
    {
        if (!vis[x])
        {
            dfs(x);
            currSet.erase(currSet.begin(), currSet.end());
        }
    }
    for (int x = 0; x < N; x++)
    {
        cout << ans[x] << endl;
    }
}