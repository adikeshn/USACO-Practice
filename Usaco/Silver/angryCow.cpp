#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

bool checkTrue(int x, vector<int> bales);

int N, K;
int main()
{
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int max, min;
    fin >> N >> K;
    vector<int> bales(N);
    for (int x = 0; x < N; x++)
    {
        fin >> bales[x];
    }
    sort(bales.begin(), bales.end());
    int answer = (bales[N - 1] - bales[0]) / (K * 2);
    answer++;
    int L = 1, R = answer;
    while (L <= R)
    {
        int mid = L + ((R - L) / 2);
        if (checkTrue(mid, bales))
        {
            answer = mid;
            R = mid - 1;
        }
        else
            L = mid + 1;
    }
    fout << answer << endl;
}

bool checkTrue(int x, vector<int> bales)
{
    int currentDistance = 0, currentCount = 0;
    for (int y = 0; y < N; y++)
    {
        if (bales[y] > currentDistance)
        {
            currentCount++;
            currentDistance = (x * 2) + (bales[y]);
        }
        if (currentCount > K)
        {
            currentCount = -1;
            break;
        }
    }
    if (currentCount != -1)
    {
        return true;
    }
    return false;
}