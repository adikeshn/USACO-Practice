#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <math.h>
using namespace std;
struct point
{
    long long x, y;
};
int main()
{
    map<long long, long long> xvals, yvals, xplus, yplus, xmin, ymin;
    vector<point> points;
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int N;
    long long ans = 0;
    fin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        fin >> x >> y;
        if (xvals.find(x) != xvals.end())
        {
            xvals[x] += abs(y);
            if (y < 0)
                xplus[x]++;
            else
                xmin[x]++;
        }
        else
        {
            xvals[x] = abs(y);
            if (y < 0)
                xplus[x] = 1;
            else
                xmin[x] = 1;
        }
        if (yvals.find(y) != yvals.end())
        {
            yvals[y] += abs(x);
            if (x < 0)
                yplus[y]++;
            else
                ymin[y]++;
        }
        else
        {
            yvals[y] = abs(x);
            if (x < 0)
                yplus[y] = 1;
            else
                ymin[y] = 1;
        }
        point n = {x, y};
        points.push_back(n);
    }
    for (point p : points)
    {
        long long sumx, sumy;
        if (p.y >= 0)
            sumx = abs(xvals[p.x] - (xmin[p.x] * p.y) + (xplus[p.x] * p.y));
        else
            sumx = abs(xvals[p.x] - (xplus[p.x] * abs(p.y)) + (xmin[p.x] * abs(p.y)));
        if (p.x >= 0)
            sumy = abs(yvals[p.y] - (ymin[p.y] * p.x) + (yplus[p.y] * p.x));
        else
            sumy = abs(yvals[p.y] - (yplus[p.y] * abs(p.x)) + (ymin[p.y] * abs(p.x)));
        ans += (sumx * sumy);
    }
    fout << ans % 1000000007;
    // iterate using aut
}