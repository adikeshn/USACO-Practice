#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("pairup.in");
    ofstream fout("pairup.out");

    vector<pair<int, int>> nums;
    int N;
    fin >> N;
    for (int x = 0; x < N; x++)
    {
        int a, b;
        fin >> a >> b;
        nums.push_back({b, a});
    }
    int p1 = 0, p2 = nums.size() - 1, ans = 0;
    sort(nums.begin(), nums.end());
    while (p1 <= p2)
    {
        ans = max(ans, nums[p1].first + nums[p2].first);
        int m = min(nums[p1].second, nums[p2].second);
        nums[p1].second -= m;
        nums[p2].second -= m;
        if (nums[p1].second <= 0)
            p1++;
        if (nums[p2].second <= 0)
            p2--;
    }
    fout << ans;
}