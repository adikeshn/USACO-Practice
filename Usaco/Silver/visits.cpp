#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int N;
    ll answer = 0;
    cin >> N;
    vector<pii> buddies(N);
    for (int x = 0; x < N; x++)
    {
        cin >> buddies[x].second >> buddies[x].first;
        buddies[x].second--;
        answer += buddies[x].first;
    }

    vector<bool> vis(N, false);
    for (int x = 0; x < N; x++)
    {
        if (!vis[x])
        {
            vector<pii> path;
            int chosen = x;
            while (!vis[chosen])
            {

                vis[chosen] = true;
                path.push_back(buddies[chosen]);
                int next = buddies[chosen].second;
                if (vis[next])
                {
                    auto start = find(path.begin(), path.end(), buddies[next]);
                    if (start != path.end())
                    {
                        answer -= min_element(start, path.end())->first;
                        break;
                    }
                }
                chosen = next;
            }
        }
    }
    cout << answer;
}