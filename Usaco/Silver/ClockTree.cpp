#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> tree[2501];
vector<int> rooms(2501);
vector<int> s, vis(2501, 0), bi, bii;
int N;
void findIfTrue(int start, int curr)
{
    if (curr == 0)
        bi.push_back(rooms[start]);
    else
        bii.push_back(rooms[start]);
    vis[start] = 1;
    for (int x : tree[start])
    {
        if (vis[x] == 0)
        {
            if (curr == 0)
                findIfTrue(x, 1);
            else
                findIfTrue(x, 0);
        }
    }
}

int main()
{
    ifstream fin("clocktree.in");
    ofstream fout("clocktree.out");
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        int a;
        fin >> a;
        rooms[x] = abs(a);
    }
    for (int x = 0; x < N - 1; x++)
    {
        int n, a;
        fin >> n >> a;
        tree[n - 1].push_back(a - 1);
        tree[a - 1].push_back(n - 1);
    }
    int ans = 0;
    findIfTrue(0, 0);
    int sum = 0, suum = 0;
    for (int x : bi)
    {
        cout << x << " ";
        sum += x;
        if (sum > 12)
            sum -= 12;
    }
    cout << endl;
    for (int x : bii)
    {
        cout << x << " ";
        suum += x;
        if (suum > 12)
            suum -= 12;
    }
    if (sum == suum)
        fout << N;
    else if (suum + 1 == sum)
        fout << bi.size();
    else if (sum + 1 == suum)
        fout << bii.size();
    else
        fout << 0;
}