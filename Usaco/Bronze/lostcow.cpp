#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    int x, y, steps, mult = 1;
    bool sub = false;
    fin >> x >> y;
    int current = x;
    if (y > x)
    {
        while (current < y)
        {
            if (sub)
            {
                steps += abs(current - (x - mult));
                current = x - mult;
                sub = false;
            }
            else
            {
                steps += abs(current - (x + mult));
                current = x + mult;
                sub = true;
            }
            mult *= 2;
        }
    }
    else
    {
        while (current > y)
        {
            if (sub)
            {
                steps += abs(current - (x - mult));
                current = x - mult;
                sub = false;
            }
            else
            {
                steps += abs(current - (x + mult));
                current = x + mult;
                sub = true;
            }
            mult *= 2;
        }
    }
    fout << steps - abs(current - y);
}