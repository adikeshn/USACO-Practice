#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1501

int N, Q;
char Directions[MAXN][MAXN];
int Following[MAXN][MAXN] = {1}, rowVals[MAXN], colVals[MAXN];
bool InitVis[MAXN][MAXN] = {false};

int findAns()
{
    int sum = 0;
    for (int x = 0; x < N; x++)
    {
        if (Directions[N - 1][x] == 'D')
        {
            sum += Following[N - 1][x] * colVals[x];
        }
    }
    for (int x = 0; x < N; x++)
    {
        if (Directions[x][N - 1] == 'R')
        {
            sum += Following[x][N - 1] * rowVals[x];
        }
    }
    return sum;
}

void subtract(int x, int y, int FollowSum, int i)
{
    if (Directions[x][y] == 'R' && y != N - 1)
    {
        Following[x][y + 1] += FollowSum * i;
        subtract(x, y + 1, FollowSum, i);
    }
    else if (Directions[x][y] == 'D' && x != N - 1)
    {
        Following[x + 1][y] += FollowSum * i;
        subtract(x + 1, y, FollowSum, i);
    }
}

int main()
{
    cin >> N;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            cin >> Directions[x][y];
        }
        cin >> rowVals[x];
    }
    for (int x = 0; x < N; x++)
    {
        cin >> colVals[x];
    }

    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            Following[x][y] = 1;
            if (x > 0 && Directions[x - 1][y] == 'D')
            {
                Following[x][y] += Following[x - 1][y];
            }
            if (y > 0 && Directions[x][y - 1] == 'R')
            {
                Following[x][y] += Following[x][y - 1];
            }
        }
    }
    cout << findAns() << endl;
    cin >> Q;
    for (int x = 0; x < Q; x++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        subtract(a, b, Following[a][b], -1);
        if (Directions[a][b] == 'D')
            Directions[a][b] = 'R';
        else
            Directions[a][b] = 'D';
        subtract(a, b, Following[a][b], 1);
        cout << findAns() << endl;
    }
}