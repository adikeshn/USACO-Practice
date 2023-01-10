#include <iostream>
#include <fstream>
#define ll long long
using namespace std;

ll solve(ll a, ll b)
{
    int stepsCurr = 0;
    if (a > b)
    {
        if (a % 2 == 1)
        {
            stepsCurr++;
        }
        stepsCurr++;
        stepsCurr += solve((a + (a % 2)) / 2, b);
    }
    else if (a < b)
    {
        stepsCurr += min(b - a, solve(a, (b - (b % 2)) / 2) + 1 + (b % 2));
    }

    return stepsCurr;
}

int main()
{
    int N;
    cin >> N;
    for (int x = 0; x < N; x++)
    {
        ll a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}
