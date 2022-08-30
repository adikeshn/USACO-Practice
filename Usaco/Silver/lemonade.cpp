#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");
    int N, ans = 0;
    fin >> N;
    vector<int> cows;
    for (int x = 0; x < N; x++)
    {
        int a;
        fin >> a;
        cows.push_back(a);
    }
    sort(cows.begin(), cows.end(), greater<int>());
    for (int x = 0; x < cows.size(); x++)
    {
        if (cows[x] >= x)
            ans++;
    }
    fout << ans;
}