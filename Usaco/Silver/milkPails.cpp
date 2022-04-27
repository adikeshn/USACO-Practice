#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
bool vis[200] = {false};
int X, Y;
vector<int> dfs(int currdepth, int depth, vector<int> curPail, vector<int> sums)
{
    if (currdepth < depth)
    {
        if (vis[curPail[0] + curPail[1]] == false)
        {
            vis[curPail[0] + curPail[1]] = true;
            sums.push_back(curPail[0] + curPail[1]);
            int x = curPail[0], y = curPail[1];
            vector<int> temp = curPail;
            temp[0] = 0;
            sums = dfs(currdepth + 1, depth, temp, sums);
            temp[0] = x;
            temp[1] = 0;
            sums = dfs(currdepth + 1, depth, temp, sums);
            temp[1] = y;
            temp[0] += temp[1];
            if (temp[0] > X)
            {
                temp[1] -= temp[0] - X;
                temp[0] = X;
            }
            else
            {
                temp[1] = 0;
            }
            sums = dfs(currdepth + 1, depth, temp, sums);
            temp[0] = x;
            temp[1] = y;
            temp[1] += temp[0];
            if (temp[1] > Y)
            {
                temp[0] -= temp[1] - Y;
                temp[1] = Y;
            }
            else
            {
                temp[0] = 0;
            }
            sums = dfs(currdepth + 1, depth, temp, sums);
            temp[0] = X;
            temp[1] = y;
            sums = dfs(currdepth + 1, depth, temp, sums);
            temp[0] = x;
            temp[1] = Y;
            sums = dfs(currdepth + 1, depth, temp, sums);
        }
    }
    return sums;
}

int main()
{
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int K, M;
    fin >> X >> Y >> K >> M;
    vector<int> curPail(2, 0), i, ans;
    ans = dfs(0, K, curPail, i);
    for (int x = 0; x < ans.size(); x++)
    {
        cout << x << endl;
    }
}