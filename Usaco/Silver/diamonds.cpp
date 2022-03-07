#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int N, K;
    fin >> N >> K;
    vector<int> cows(N);
    for (int x = 0; x < N; x++)
    {
        fin >> cows[x];
    }
    if (cows.size() == 1 || cows.size() == 0)
    {
        fout << cows.size();
        return 0;
    }
    sort(cows.begin(), cows.end());
    cout << cows[N - 190] << endl;
    int start, end, max = 0;
    for (int x = 0; x < N; x++)
    {
        int curr = 1, l = x;
        for (int y = x + 1; y < N; y++)
        {
            if (cows[y] - cows[x] <= K)
            {
                curr++;
                l = y;
            }
            else
            {
                break;
            }
        }
        if (curr > max)
        {
            max = curr;
            start = x;
            end = l;
        }
    }
    max = end - start + 1;
    cows.erase(cows.begin() + start, cows.begin() + end + 1);
    cout << start << " " << end;
    if (cows.size() == 0 || cows.size() == 1)
    {
        fout << max + cows.size();
        return 0;
    }
    int maxn = 0;
    for (int x = 0; x < cows.size(); x++)
    {
        int curr = 1, l = x;
        for (int y = x + 1; y < cows.size(); y++)
        {
            if (cows[y] - cows[x] <= K)
            {
                curr++;
                l = y;
            }
            else
            {
                break;
            }
        }
        if (curr > maxn)
        {
            maxn = curr;
            start = x;
            end = l;
        }
    }
    maxn = end - start + 1;

    fout << maxn + max;
}