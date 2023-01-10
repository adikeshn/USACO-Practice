#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> connectedComp;
vector<pair<int, int>> positions;
vector<pair<int, pair<int, int>>> wormholes;

void createComp(int curr, int comp, vector<int> graph[])
{
    connectedComp[curr] = comp;
    for (int x : graph[curr])
    {
        if (connectedComp[x] == -1)
        {
            createComp(x, comp, graph);
        }
    }
}

bool solve(int currMid)
{

    vector<int> graph[N];

    for (int x = 0; x < wormholes.size(); x++)
    {
        if (wormholes[x].first >= currMid)
        {
            graph[wormholes[x].second.first].push_back(wormholes[x].second.second);
            graph[wormholes[x].second.second].push_back(wormholes[x].second.first);
        }
        else
            break;
    }

    connectedComp = vector<int>(N, -1);
    int currComp = 0;
    for (int x = 0; x < N; x++)
    {
        if (connectedComp[x] == -1)
        {
            createComp(x, currComp, graph);
            currComp++;
        }
    }

    for (int x : connectedComp)
    {
        cout << x << " ";
    }

    for (pair<int, int> x : positions)
    {
        if (connectedComp[x.first] != connectedComp[x.second])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    fin >> N >> M;
    for (int x = 0; x < N; x++)
    {
        int a;
        fin >> a;

        if (a - 1 != x)
        {
            positions.push_back({a - 1, x});
        }
    }

    if (positions.size() == 0)
    {
        fout << -1;
        return 0;
    }

    for (int x = 0; x < M; x++)
    {
        int t1, t2, weight;
        fin >> t1 >> t2 >> weight;
        wormholes.push_back({weight, {t1 - 1, t2 - 1}});
    }

    sort(wormholes.begin(), wormholes.end(), greater<pair<int, pair<int, int>>>());
    int L = 0, R = wormholes.size() - 1, mid, ans = 0;
    while (L <= R)
    {
        mid = L + ((R - L) / 2);
        cout << wormholes[mid].first << endl;
        if (solve(wormholes[mid].first))
        {
            R = mid - 1;
            ans = max(ans, wormholes[mid].first);
        }
        else
        {
            L = mid + 1;
        }
    }
    fout << ans;
}