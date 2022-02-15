#include <iostream>
#include <vector>
using namespace std;

int vis[100001] = {};
vector<int> ar[100001], it;

void dfs(int n)
{
    vis[n] = 1;
    for (int x : ar[n])
    {
        if (vis[x] != 1)
        {
            dfs(x);
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    for (int x = 1; x < n + 1; x++)
    {
        if (vis[x] == 0)
        {
            dfs(x);
            it.push_back(x);
        }
    }
    cout << it.size() - 1 << endl;

    for (int x = 0; x < it.size() - 1; x++)
    {
        cout << it[x] << " " << it[x + 1] << endl;
    }
}