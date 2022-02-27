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
    vector<pair<int, int>> price(M);
    vector<int> farms(R), cows(N);
    vector<int> sums(N);
    for (int x = 0; x < N; x++)
    {
        fin >> cows[x];
    }
    sort(cows.begin(), cows.end(), greater<>());
    for (int x = 0; x < M; x++)
    {
        fin >> price[x].second >> price[x].first;
    }
    sort(price.begin(), price.end(), compare);
    for (int x = 0; x < R; x++)
    {
        fin >> farms[x];
    }
    sort(farms.begin(), farms.end(), greater<>());

    for (int x = 0; x < N; x++)
    {
        int sum = cows[x], curr = 0;
        while (sum != 0 && price.size() != 0)
        {
            if (sum >= price[0].second)
            {
                curr += price[0].first * price[0].second;
                sum -= price[0].second;
                price.erase(price.begin());
            }
            else
            {
                curr += price[0].first * (sum);
                price[0].second -= sum;
                sum = 0;
            }
        }
        sums[x] = curr;
    }
    long long answer;
    for (int x = N - 1; x >= 0; x--)
    {
        if (sums[x] < farms[0] && farms.size() != 0)
        {
            sums[x] = farms[0];
            farms.erase(farms.begin());
        }
        answer += sums[x];
    }
    fout << answer;
}