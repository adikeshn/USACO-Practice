#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int groups[100001] = {0}, CurrGroups, startGroup, endGroup, N;

void CreateGroups(vector<int> adjList[], int currGroup, int currNode)
{
    groups[currNode] = currGroup;
    if (currNode == 1)
        startGroup = CurrGroups;
    if (currNode == N)
        endGroup = CurrGroups;
    for (int x : adjList[currNode])
    {
        if (groups[x] == 0)
            CreateGroups(adjList, currGroup, x);
    }
}

int main()
{
    int T;
    cin >> T;
    vector<long long> anss;
    for (int x = 0; x < T; x++)
    {
        vector<int> adjList[100001];
        int M;
        cin >> N >> M;
        fill(groups, groups + N + 1, 0);
        for (int x = 0; x < M; x++)
        {
            int i, j;
            cin >> i >> j;
            adjList[i].push_back(j);
            adjList[j].push_back(i);
        }
        CurrGroups = 0;
        for (int x = 1; x <= N; x++)
        {
            if (groups[x] == 0)
            {
                CurrGroups++;
                CreateGroups(adjList, CurrGroups, x);
            }
        }
        if (startGroup == endGroup)
        {
            anss.push_back(0);
        }
        else
        {
            vector<long long> startGroups, endGroups;
            for (int x = 1; x <= N; x++)
            {
                if (groups[x] == startGroup)
                    startGroups.push_back(x);
                else if (groups[x] == endGroup)
                    endGroups.push_back(x);
            }
            long long startPointer = 0, endPointer = 0, connections[100001][2];
            for (int x = 0; x < 100001; x++)
            {
                for (int y = 0; y < 2; y++)
                {
                    connections[x][y] = -1;
                }
            }
            for (int i = 1; i <= N; i++)
            {
                long long redDist = (startGroups[startPointer] - i) * (startGroups[startPointer] - i);
                long long blueDist = (endGroups[endPointer] - i) * (endGroups[endPointer] - i);

                if (i > startGroups[startPointer] && startPointer < startGroups.size() - 1)
                {
                    redDist = min(redDist, (startGroups[startPointer + 1] - i) * (startGroups[startPointer + 1] - i));
                    if (startGroups[startPointer + 1] == i)
                        startPointer++;
                }
                if (i > endGroups[endPointer] && endPointer < endGroups.size() - 1)
                {
                    blueDist = min(blueDist, (endGroups[endPointer + 1] - i) * (endGroups[endPointer + 1] - i));
                    if (endGroups[endPointer + 1] == i)
                        endPointer++;
                }
                if (connections[groups[i]][0] == -1)
                    connections[groups[i]][0] = redDist;
                else
                    connections[groups[i]][0] = min(connections[groups[i]][0], redDist);
                if (connections[groups[i]][1] == -1)
                    connections[groups[i]][1] = blueDist;
                else
                    connections[groups[i]][1] = min(connections[groups[i]][1], blueDist);
            }
            long long ans = connections[1][0] + connections[1][1];
            for (int x = 1; x <= CurrGroups; x++)
            {
                ans = min(ans, connections[x][0] + connections[x][1]);
            }
            anss.push_back(ans);
        }
    }
    for (long long x : anss)
    {
        cout << x << endl;
    }
}