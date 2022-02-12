#include <iostream>
using namespace std;

int main()
{
    int nums[1] = {-2};
    int sums[sizeof(nums) / sizeof(int)];
    sums[0] = nums[0];
    int currentMax = sums[0];
    for (int x = 1; x < sizeof(nums) / sizeof(int); x++)
    {
        if (nums[x] > sums[x - 1] + nums[x])
        {
            sums[x] = nums[x];
        }
        else
        {
            sums[x] = sums[x - 1] + nums[x];
        }

        if (sums[x] > currentMax)
        {
            currentMax = sums[x];
        }
    }
    cout << currentMax;
}