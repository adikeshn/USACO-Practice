#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
bool vis[101][101][101] = {false};
int X, Y, solution = 200, K, M;
void dfs(int currdepth, int curX, int curY)
{
    if (currdepth > K || vis[curX][curY][currdepth])
        return;
    vis[curX][curY][currdepth] = true;
    solution = min(solution, abs(M - (curX + curY)));
    dfs(currdepth + 1, 0, curY);
    dfs(currdepth + 1, curX, 0);

    dfs(currdepth + 1, X, curY);
    dfs(currdepth + 1, curX, Y);

    if (curX + curY > X)
        dfs(currdepth + 1, X, curY - (X - curX));
    else
        dfs(currdepth + 1, curX + curY, 0);

    if (curX + curY > Y)
        dfs(currdepth + 1, curX - (Y - curY), Y);
    else
        dfs(currdepth + 1, 0, curX + curY);
}

int main()
{
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    fin >> X >> Y >> K >> M;
    dfs(0, 0, 0);
    fout << solution << endl;
}