#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> nums(100001, false);
vector<int> oppNumsFirst, oppNumsSecond;

int main()
{
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");

    int N;
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        int a;
        fin >> a;
        if (oppNumsFirst.size() < N / 2)
        {
            oppNumsFirst.push_back(a);
        }
        else
            oppNumsSecond.push_back(a);
        nums[a] = true;
    }
    vector<int> firstHalf, SecondHalf;
    for (int x = 1; x <= 2 * N; x++)
    {
        if (!nums[x])
        {
            if (firstHalf.size() < N / 2)
                firstHalf.push_back(x);
            else
                SecondHalf.push_back(x);
        }
    }

    int ans = 0;
    for (int x : oppNumsFirst)
    {
        auto num = upper_bound(SecondHalf.begin(), SecondHalf.end(), x);
        if (num != SecondHalf.end())
        {
            cout << *num << " " << x << endl;

            ans++;
            SecondHalf.erase(num);
        }
    }
    for (int x : oppNumsSecond)
    {
        auto num = upper_bound(firstHalf.begin(), firstHalf.end(), x);
        if (num != firstHalf.begin())
            --num;
        if (*num < x)
        {
            cout << *num << " " << x << endl;

            ans++;
            firstHalf.erase(num);
        }
    }
    fout << ans;
}
