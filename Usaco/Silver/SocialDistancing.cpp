#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct interval
{
    long long start, end;
};

int N, M;

vector<interval> intervals;

bool compare(interval a, interval b)
{
    return a.start < b.start;
}

bool CheckValid(int d)
{
    int currSpot = intervals[0].start;
    for (int x = 0; x < N; x++)
    {
        cout << currSpot << " ";

        int L = 0, R = intervals.size() - 1, mid;
        bool found = false;
        while (L <= R)
        {
            mid = L + ((R - L) / 2);
            if (currSpot >= intervals[mid].start && currSpot <= intervals[mid].end)
            {
                found = true;
                break;
            }
            else if (currSpot > intervals[mid].end)
                L = mid + 1;
            else if (currSpot < intervals[mid].start)
                R = mid - 1;
        }
        if (!found && (L + ((R - L) / 2)) > intervals.size() - 1)
        {
            return false;
        }
        else
        {
            if (!found)
                currSpot = intervals[(L + ((R - L) / 2))].start + d;
            else
                currSpot += d;
        }
    }
    cout << currSpot << " ";

    return true;
}

int main()
{
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");
    fin >> N >> M;
    for (int x = 0; x < M; x++)
    {
        interval n;
        fin >> n.start >> n.end;
        intervals.push_back(n);
    }
    sort(intervals.begin(), intervals.end(), compare);
    int L = 1, R = intervals[intervals.size() - 1].end, mid;
    int ans = 0;
    while (L <= R)
    {
        mid = L + ((R - L) / 2);
        cout << mid << " ";
        if (CheckValid(mid))
        {
            L = mid + 1;
            ans = mid;
        }
        else
        {
            R = mid - 1;
        }
        cout << endl;
    }
    fout << ans;
}