#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct point
{
    int x;
    int y;
    int id;
    bool isactive;
};

int dfs(vector<int> n, vector<int> inter[])
{
    int ans = 0;
    for (int x : n)
    {
        ans++;
        ans += dfs(inter[x], inter);
    }
    return ans;
}

bool compare(const point &a, const point &b)
{
    return a.y < b.y;
}

bool compare2(const point &a, const point &b)
{
    return a.x < b.x;
}

int main()
{
    int N;
    cin >> N;
    vector<point> north;
    vector<point> east;
    vector<int> inter[N];
    for (int x = 0; x < N; x++)
    {
        char a;
        point b;
        cin >> a >> b.x >> b.y;
        b.id = x;
        b.isactive = true;
        if (a == 'E')
            east.push_back(b);
        else
            north.push_back(b);
    }

    sort(east.begin(), east.end(), compare);
    sort(north.begin(), north.end(), compare2);

    for (int x = 0; x < east.size(); x++)
    {
        for (int y = 0; y < north.size(); y++)
        {
            if (north[y].x > east[x].x && north[y].y < east[x].y)
            {
                if (north[y].x - east[x].x < east[x].y - north[y].y && north[y].isactive && east[x].isactive)
                {
                    inter[east[x].id].push_back(north[y].id);
                    north[y].isactive = false;
                    //cout << east[x].x << " " << east[x].y << " " << north[y].x << " " << north[y].y << "bad" << endl; //
                }
                else if (north[y].x - east[x].x > east[x].y - north[y].y && east[x].isactive && north[y].isactive)
                {
                    inter[north[y].id].push_back(east[x].id);
                    east[x].isactive = false;
                    //cout << east[x].x << " " << east[x].y << " " << north[y].x << " " << north[y].y << "good" << endl; //
                }
            }
        }
    }
    for (int x = 0; x < N; x++)
    {
        cout << dfs(inter[x], inter) << endl;
    }
}