#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int N, answer, chosen = 0, mult = 0;
    fin >> N;
    int ar[3] = {1, 2, 3};
    int swaps[N][3];
    for (int x = 0; x < N; x++)
    {
        fin >> swaps[x][0];
        fin >> swaps[x][1];
        fin >> swaps[x][2];
    }
    int guesses[N];
    for (int x = 0; x < N; x++)
    {
        int tmp = ar[swaps[x][0] - 1];
        ar[swaps[x][0] - 1] = ar[swaps[x][1] - 1];
        ar[swaps[x][1] - 1] = tmp;
        guesses[x] = ar[swaps[x][2] - 1];
    }
    sort(guesses, guesses + N);
    for (int x : guesses)
    {
        if (chosen != x)
        {
            if (mult > answer)
            {
                answer = mult;
            }
            chosen = x;
            mult = 1;
        }
        else
        {
            mult++;
        }
    }
    if (mult > answer)
    {
        answer = mult;
    }
    fout << answer;
}