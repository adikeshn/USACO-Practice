#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

int C, N;
struct Time
{
    int time;
    int id;
    bool isstart;
};

bool compare(const Time &a, const Time &b)
{
    return a.time < b.time;
}

int main()
{
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");
    fin >> C >> N;
    int chicks[C], seen[C], ans = 0;
    bool taken[C];
    vector<Time> cows;
    vector<pair<int, int> > times(N);
    set<int> active;
    for (int x = 0; x < C; x++)
    {
        fin >> chicks[x];
        taken[x] = false;
    }
    for (int x = 0; x < N; x++)
    {
        Time a, b;
        a.id = x;
        a.isstart = true;
        b.id = x;
        b.isstart = false;
        fin >> a.time >> b.time;
        times[x].first = a.time;
        times[x].second = b.time;
        cout << a.time << b.time << endl;
        cows.push_back(a);
        cows.push_back(b);
    }
    sort(chicks, chicks + C);
    sort(cows.begin(), cows.end(), compare);
    for (int x = 0; x < N * 2; x++)
    {
        cout << cows[x].time;
    }
    cout << endl;
    for (Time x : cows)
    {
        if (x.isstart == true)
        {
            active.insert(x.id);
        }
        else
        {
            for (int y = 0; y < C; y++)
            {
                if (chicks[y] >= times[x.id].first && chicks[y] <= times[x.id].second && taken[y] == false)
                {
                    cout << times[x.id].first << " " << times[x.id].second << " " << chicks[y] << endl;
                    taken[y] = true;
                    ans++;
                    break;
                }
            }
            active.erase(x.id);
        }
    }
    fout << ans;
}