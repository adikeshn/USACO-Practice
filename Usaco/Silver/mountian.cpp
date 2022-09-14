#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    int x, y;
};

bool compare(point a, point b)
{
    return a.y > b.y;
}

int main()
{
    ifstream fin("mountains.in");
    ofstream fout("mountains.out");
    int N;
    fin >> N;
    int answer = N;
    vector<point> points;
    int maxs[N][2];
    for (int x = 0; x < N; x++)
    {
        point a;
        fin >> a.x >> a.y;
        points.push_back(a);
    }
    sort(points.begin(), points.end(), compare);
    for (int x = 0; x < N; x++)
    {
        maxs[x][0] = points[x].x + points[x].y;
        maxs[x][1] = points[x].x - points[x].y;
        cout << maxs[x][0] << " " << maxs[x][1] << endl;
    }
    for (int x = 1; x < N; x++)
    {
        for (int y = 0; y < x; y++)
        {
            if (maxs[x][1] > maxs[y][1] && maxs[x][0] < maxs[y][0])
            {
                cout << x << y;
                answer--;
                break;
            }
        }
    }
    fout << answer;
    cout << answer;
}