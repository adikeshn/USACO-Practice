#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    map<int, vector<int>> xvals, yvals;
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int N, maxY = 0, minY = 100001, maxX = 0, minX = 100001;
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        vector<int> l, n;
        int b, y;
        fin >> b >> y;
        if (xvals.find(b) != xvals.end())
            xvals[b].push_back(y);
        else
        {
            l.push_back(y);
            xvals[b] = l;
        }
        if (yvals.find(y) != yvals.end())
            yvals[y].push_back(b);
        else
        {
            n.push_back(b);
            yvals[y] = n;
        }
        maxY = max(y, maxY);
        minY = min(y, minY);
        maxX = max(b, maxX);
        minX = min(b, minX);
    }
    cout << maxY << minY << maxX << minX;
}