#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(vector<int> input, int baskets, int numMax);

int main()
{
    ifstream fin("berries.in");
    ofstream fout("berries.out");

    int N, K, answer, x = 1;
    fin >> N >> K;
    vector<int> trees(N);

    for (int x = 0; x < N; x++)
    {
        fin >> trees[x];
    }
    int max = *max_element(trees.begin(), trees.end());
    sort(trees.begin(), trees.end(), greater<>());
    int L = 1, R = max;
    while (L <= R)
    {
        int mid = L + ((R - L) / 2);
        int a = solve(trees, K, mid), b = solve(trees, K, mid - 1);
        if (a > b)
        {
            answer = a;
            L = mid + 1;
        }
        else
            R = mid - 1;
    }
    cout << answer;
    fout << answer;
}

int solve(vector<int> input, int baskets, int numMax)
{
    vector<int> b;
    int num = 0, sum = 0;
    while (b.size() < baskets)
    {
        if (input[0] >= numMax)
        {
            input[0] -= numMax;
            b.push_back(numMax);
            num++;
            if (num > baskets / 2)
                sum += numMax;
        }
        else
        {
            numMax--;
        }
        if (input[0] < input[1])
        {
            sort(input.begin(), input.end(), greater<>());
        }
    }
    return sum;
}