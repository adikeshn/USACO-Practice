#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

    int buckets[3][2], count = 0;
    for (int x = 0; x < 3; x++)
    {
        fin >> buckets[x][0];
        fin >> buckets[x][1];
    }
    int next;
    while (count < 100)
    {
        for (int x = 0; x < 3; x++)
        {
            if (x == 2)
            {
                next = 0;
            }
            else
            {
                next = x + 1;
            }
            if (buckets[x][1] + buckets[next][1] > buckets[next][0])
            {
                buckets[x][1] -= buckets[next][0] - buckets[next][1];
                buckets[next][1] = buckets[next][0];
            }
            else
            {
                buckets[next][1] += buckets[x][1];
                buckets[x][1] = 0;
            }
            count++;
            if (count == 100)
            {
                break;
            }
        }
    }
    for (int x = 0; x < 3; x++)
    {
        fout << buckets[x][1] << endl;
    }
}