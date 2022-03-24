#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

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
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int n;
    fin >> n;
    vector<Time> times;
    for (int x = 0; x < n; x++)
    {
        Time n, l;
        fin >> n.time >> l.time;
        l.isstart = false;
        n.isstart = true;
        l.id = x + 1;
        n.id = x + 1;
        times.push_back(n);
        times.push_back(l);
    }
    vector<int> alone(n, 0);
    int current, prev = 0, total = 0;
    set<int> s;
    sort(times.begin(), times.end(), compare);
    for (int x = 0; x < n * 2; x++)
    {
        current = times[x].time;
        if (!s.empty())
        {
            total += current - prev;
        }
        if (s.size() == 1)
        {
            alone[*s.begin()] += current - prev;
        }
        if (times[x].isstart == true)
            s.insert(times[x].id - 1);
        else
            s.erase(times[x].id - 1);
        prev = current;
    }
    fout << total - *min_element(alone.begin(), alone.end());
}