#include <iostream>
#include <vector>
using namespace std;

int N, subtree[2 * 100001] = {};
vector<int> company[2 * 100001];

void findSubs(int x)
{
    subtree[x] = 1;
    for (int y : company[x])
    {
        findSubs(y);
        subtree[x] += subtree[y];
    }
}

int main()
{
    cin >> N;
    int a;
    for (int x = 2; x < N + 1; x++)
    {
        cin >> a;
        company[a].push_back(x);
    }

    cout << N - 1 << " ";
    findSubs(1);
    for (int x = 2; x < N + 1; x++)
    {
        cout << subtree[x] - 1 << " ";
    }
}