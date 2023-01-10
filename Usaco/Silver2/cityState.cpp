#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;

int main()
{
    ifstream fin("citystate.in");
    ofstream fout("citystate.out");
    unordered_map<string, long long> nums;
    int N;
    long long ans = 0;
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        string cityName, State;
        fin >> cityName >> State;
        if (cityName[0] != State[0] || cityName[1] != State[1])
        {
            string l = {cityName[0], cityName[1], State[0], State[1]};
            if (nums.find(l) == nums.end())
            {
                nums[l] = 0;
            }
            nums[l]++;
        }
    }
    for (auto x : nums)
    {
        string l = {x.first[2], x.first[3], x.first[0], x.first[1]};
        if (nums.find(l) != nums.end())
            ans += x.second * nums[l];
    }
    fout << ans / 2;
}