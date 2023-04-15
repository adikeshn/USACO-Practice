#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;

vector<int> nums, newPositions;
vector<bool> vis;
vector<vector<int>> cycles;

int main()
{
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    fin >> N >> M >> K;

    newPositions.resize(N);
    vis = vector<bool>(N, false);
    vector<int> ans(N);

    for (int x = 0; x < N; x++)
    {
        nums.push_back(x);
    }
    for (int x = 0; x < M; x++)
    {
        int a, b;
        fin >> a >> b;
        reverse(nums.begin() + a - 1, nums.begin() + b);
    }
    for (int x = 0; x < N; x++)
    {
        newPositions[nums[x]] = x;
    }
    for (int x = 0; x < N; x++)
    {
        if (!vis[x])
        {
            int curr = x;
            vector<int> curCycle;
            while (!vis[curr])
            {
                vis[curr] = true;
                curCycle.push_back(curr);
                curr = newPositions[curr];
            }
            int add = K % curCycle.size();
            for (int x = 0; x < curCycle.size(); x++)
            {
                if (x + add > curCycle.size() - 1)
                {
                    ans[curCycle[add - (curCycle.size() - x)]] = curCycle[x] + 1;
                }
                else
                    ans[curCycle[x + add]] = curCycle[x] + 1;
            }
        }
    }
    for (int x : ans)
    {
        fout << x << endl;
    }
}