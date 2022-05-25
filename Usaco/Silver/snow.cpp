#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct boot
{
    int depth;
    int step;
};
int N, B, ans = 250;
vector<int> path(250);
vector<boot> boots(250);
bool vis[250][250] = {false};

void findmin(int currdepth, int currboot)
{
    if (vis[currdepth][currboot])
        return;
    vis[currdepth][currboot] = true;

    if (currdepth == N - 1)
    {
        ans = min(ans, currboot);
    }

    for (int x = 1; currboot + x < B; x++)
    {
        if (boots[currboot + x].depth >= path[currdepth])
            findmin(currdepth, currboot + x);
    }

    for (int x = 1; x <= boots[currboot].step && currdepth + x < N; x++)
    {
        if (path[currdepth + x] <= boots[currboot].depth)
            findmin(currdepth + x, currboot);
    }
}

int main()
{
    ifstream fin("snowboots.in");
    ofstream fout("snowboots.out");
    fin >> N >> B;
    for (int x = 0; x < N; x++)
    {
        fin >> path[x];
    }
    for (int x = 0; x < B; x++)
    {
        boot n;
        fin >> n.depth >> n.step;
        boots[x] = n;
    }
    findmin(0, 0);
    fout << ans;
}