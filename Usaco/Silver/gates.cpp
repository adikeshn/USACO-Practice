#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int ans = 0;

int main()
{
    ifstream fin("gates.in");
    ofstream fout("gates.out");
    int x = 0, y = 0, N;
    pair<int, int> prev;
    prev.first = x;
    prev.second = y;
    fin >> N;
    set<pair<pair<int, int>, pair<int, int>>> visnode;
    set<pair<int, int>> vis;
    vis.insert(prev);
    for (int i = 0; i < N; i++)
    {
        char n;
        fin >> n;
        if (n == 'N')
            y++;
        else if (n == 'S')
            y--;
        else if (n == 'E')
            x++;
        else if (n == 'W')
            x--;
        pair<int, int> curr;
        curr.first = x;
        curr.second = y;
        if (visnode.find({curr, prev}) == visnode.end() &&
            visnode.find({prev, curr}) == visnode.end() &&
            vis.find(curr) != vis.end())
        {
            ans++;
        }
        visnode.insert({curr, prev});
        visnode.insert({prev, curr});
        vis.insert(curr);
        prev = curr;
    }
    fout << ans;
}