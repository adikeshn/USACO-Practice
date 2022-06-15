#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> tree[101];
vector<int> rooms(101);
int N;
bool findIfTrue(int start, vector<int> s, int k)
{
    if (k == N)
    {
        return true;
    }
    for (int x : tree[start])
    {
        if (s[x] != 0)
        {
            s[x]--;
            if (s[x] == 0)
            {
                k++;
            }
            if (findIfTrue(x, s, k))
                return true;
        }
    }
    return false;
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
        rooms[x] = abs(12 - a);
    }
    for (int x = 0; x < N - 1; x++)
    {
        int n, a;
        fin >> n >> a;
        tree[n - 1].push_back(a - 1);
        tree[a - 1].push_back(n - 1);
    }
    int ans = 0;
    for (int x = 0; x < N; x++)
    {
        vector<int> sl = rooms;
        if (findIfTrue(x, sl, 0))
            cout << x;
    }
}