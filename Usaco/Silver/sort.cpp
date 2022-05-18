#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Entry
{
    int index;
    int value;
};
bool compare(Entry a, Entry b)
{
    return a.value < b.value || (a.value == b.value && a.index < b.index);
}
int main()
{
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int N;
    fin >> N;
    Entry ar[N];
    for (int x = 0; x < N; x++)
    {
        Entry y;
        y.index = x;
        fin >> y.value;
        ar[x] = y;
    }
    sort(ar, ar + N, compare);
    int ans = 1;
    for (int x = 0; x < N; x++)
    {
        cout << ar[x].value << " ";
        ans = max(ans, 1 + ar[x].index - x);
    }
    fout << ans;
}