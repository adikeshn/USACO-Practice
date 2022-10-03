#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void checkPoint(int x, int y);
void findPoint(int x, int y);
void checkValid(int x, int y);

struct point
{
    int around = 0;
    bool added = false, real = false;
};
point grid[4000][4000];
int currAns = 0;

int main()
{
    int N;
    cin >> N;
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        grid[x + 2000][y + 2000].real = true;
        if (grid[x + 2000][y + 2000].added && grid[x + 2000][y + 2000].real)
        {
            currAns--;
        }
        else
        {
            checkPoint(x + 2000, y + 2000);
        }
        ans.push_back(currAns);
    }
    for (int x : ans)
    {
        cout << x << endl;
    }
}

void findPoint(int x, int y)
{
    if (!grid[x + 1][y].real && !grid[x + 1][y].added)
    {
        grid[x + 1][y].added = true;
        checkPoint(x + 1, y);
        return;
    }
    if (!grid[x - 1][y].real && !grid[x - 1][y].added)
    {
        grid[x - 1][y].added = true;
        checkPoint(x - 1, y);
        return;
    }
    if (!grid[x][y + 1].real && !grid[x][y + 1].added)
    {
        grid[x][y + 1].added = true;
        checkPoint(x, y + 1);
        return;
    }
    if (!grid[x][y - 1].real && !grid[x][y - 1].added)
    {
        grid[x][y - 1].added = true;
        checkPoint(x, y - 1);
        return;
    }
}

void checkValid(int x, int y, int a, int b)
{
    if (!(grid[a][b].added && grid[a][b].real))
    {
        grid[x][y].around += 1;
    }

    if (grid[x][y].added || grid[x][y].real)
    {
        if (grid[x][y].around == 3)
        {
            findPoint(x, y);
            currAns++;
        }
    }
}
void checkPoint(int x, int y)
{
    if (grid[x][y].around == 3)
    {
        findPoint(x, y);
        currAns++;
    }
    checkValid(x + 1, y, x, y);
    checkValid(x - 1, y, x, y);
    checkValid(x, y + 1, x, y);
    checkValid(x, y - 1, x, y);
}