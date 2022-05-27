#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <math.h>
using namespace std;
struct point
{
    long long int x, y;
};
int main()
{
    map<int, int> xvals, yvals, xam, yam;
    vector<point> points;
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int N;
    long double ans = 0.0;
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        fin >> x >> y;
        if (xvals.find(x) != xvals.end())
        {
            xvals[x] += y;
            xam[x]++;
        }
        else
        {
            xvals[x] = y;
            xam[x] = 1;
        }
        if (yvals.find(y) != yvals.end())
        {
            yvals[y] += x;
            yam[y]++;
        }
        else
        {
            yvals[y] = x;
            yam[y] = 1;
        }
        point n = {x, y};
        points.push_back(n);
    }
    for (point p : points)
    {
        long double sumx = abs(xvals[p.x] - (xam[p.x] * p.y)), sumy = abs(yvals[p.y] - (yam[p.y] * p.x));
        cout << p.x << p.y << sumx << sumy << endl;
        ans += (sumx * sumy) / 2.0;
    }
    long long int K = 1000000007.0;
    ans *= 2;
    fout << (long long int)(ans) % K;
    // iterate using aut
}