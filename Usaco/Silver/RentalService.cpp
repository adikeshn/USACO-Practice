#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}

int main()
{
    ifstream fin("rental.in");
    ofstream fout("rental.out");
    int N, M, R;
    fin >> N >> M >> R;
    vector<pair<long long, long long>> price(M);
    vector<int> farms(R), cows(N);
    vector<long long> sums(N), sums2(N);
    vector<long long> prefix;
    for (int x = 0; x < N; x++)
    {
        fin >> cows[x];
    }
    sort(cows.begin(), cows.end(), greater<int>());
    for (int x = 0; x < M; x++)
    {
        fin >> price[x].second >> price[x].first;
    }
    sort(price.begin(), price.end(), compare);
    for (int x = 0; x < R; x++)
    {
        fin >> farms[x];
    }
    sort(farms.begin(), farms.end(), greater<int>());
    int n = farms.size() - 1;
    long long answer = 0;
    long long b = 0;
    for (int x = 0; x < M; x++)
    {
        for (int y = 0; y < price[x].second; y++)
        {
            prefix.push_back(price[x].first + b);
            b += price[x].first;
        }
    }
    b = 0;
    long long l = 0;
    for (int x = 0; x < N; x++)
    {
        if (n >= 0 && N - x <= farms.size())
        {
            sums2[x] = farms[n];
            n--;
        }
        else
        {
            sums2[x] = 0;
        }
        cout << prefix[cows[x] + b - 1] - l << endl;
        if (cows[x] + b - 1 < prefix.size())
        {
            answer += max(prefix[cows[x] + b - 1] - l, sums2[x]);
            l += prefix[cows[x] + b - 1] - l;
            b += cows[x];
        }
        else
        {
            answer += max(prefix[prefix.size() - 1], sum2)
        }
    }
    fout << answer;
}