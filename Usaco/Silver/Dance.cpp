#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
int N, K;
vector<int> match(100001), ans(100001);
vector<int> locations[100001];

unordered_set<int> currNums;
bool vis[100001] = {false};
void dfs(int curr)
{
    vis[curr] = true;
    for (int x : locations[curr])
    {
        currNums.insert(x);
    }
    if (!vis[match[curr]])
        dfs(match[curr]);
    ans[curr] = currNums.size();
}
int main()
{
    cin >> N >> K;
    vector<int> curr;
    for (int x = 1; x < N + 1; x++)
    {
        curr.push_back(x);
        locations[x].push_back(x);
    }
    for (int x = 0; x < K; x++)
    {
        int st, end;
        cin >> st >> end;
        st--;
        end--;
        locations[curr[st]].push_back(end + 1);
        locations[curr[end]].push_back(st + 1);
        swap(curr[st], curr[end]);
    }
    for (int x = 1; x < N + 1; x++)
    {
        match[x] = curr[x - 1];
    }
    unordered_set<int> n;
    for (int x = 1; x < N + 1; x++)
    {
        if (!vis[x])
            dfs(x);
        currNums = n;
    }
    for (int x = 1; x < N + 1; x++)
    {
        cout << ans[x] << endl;
    }
}
