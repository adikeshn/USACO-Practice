#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
int C, N;

bool dfs(int chosen, vector<int> &match, int seen[], vector<int> matrix[])
{
    for (int x : matrix[chosen])
    {
        if (seen[x] == 0)
        {
            seen[x] = 1;
            if (match[x] == -1 || dfs(match[x], match, seen, matrix))
            {
                match[x] = chosen;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ifstream fin("helpcross.in");
    ofstream fout("helpcross.out");
    fin >> C >> N;
    int chicks[C], seen[C] = {}, ans = 0;
    vector<pair<int, int>> cows(N);
    vector<int> match(N, -1), matrix[N];
    for (int x = 0; x < C; x++)
    {
        fin >> chicks[x];
    }
    for (int x = 0; x < N; x++)
    {
        fin >> cows[x].first >> cows[x].second;
    }
    sort(chicks, chicks + C);
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < C; y++)
        {
            if (chicks[y] >= cows[x].first && chicks[y] <= cows[x].second)
                matrix[x].push_back(y);
            else if (chicks[y] > cows[x].second)
                break;
        }
    }

    for (int x = 0; x < N; x++)
    {
        if (dfs(x, match, seen, matrix))
            ans++;
        for (int y = 0; y < C; y++)
        {
            seen[y] = 0;
        }
    }
    fout << ans;
}