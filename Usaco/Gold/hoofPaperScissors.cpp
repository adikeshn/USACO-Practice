#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int N, numSwitch;
vector<int> moves(100002);
int dp[100002][22][3];

int main()
{
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    fin >> N >> numSwitch;
    for (int x = 1; x < N + 1; x++)
    {
        char a;
        fin >> a;
        if (a == 'H')
            moves[x] = 0;
        else if (a == 'P')
            moves[x] = 1;
        else
            moves[x] = 2;
    }
    int ans = 0;
    for (int currGame = 1; currGame < N + 1; currGame++)
    {
        for (int currSwitch = 1; currSwitch < numSwitch + 2; currSwitch++)
        {
            int add = moves[currGame] == 1;
            dp[currGame][currSwitch][0] = max(dp[currGame - 1][currSwitch][0] + add,
                                              max(dp[currGame - 1][currSwitch - 1][1] + add, dp[currGame - 1][currSwitch - 1][2] + add));

            add = moves[currGame] == 2;
            dp[currGame][currSwitch][1] = max(dp[currGame - 1][currSwitch][1] + add,
                                              max(dp[currGame - 1][currSwitch - 1][0] + add, dp[currGame - 1][currSwitch - 1][2] + add));

            add = moves[currGame] == 0;
            dp[currGame][currSwitch][2] = max(dp[currGame - 1][currSwitch][2] + add,
                                              max(dp[currGame - 1][currSwitch - 1][1] + add, dp[currGame - 1][currSwitch - 1][0] + add));
            if (currGame == N)
            {
                ans = max(ans, max(dp[currGame][currSwitch][0], max(dp[currGame][currSwitch][1], dp[currGame][currSwitch][2])));
            }
        }
    }
    fout << ans;
}
