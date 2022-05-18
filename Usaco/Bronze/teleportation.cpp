#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    int a, b, x, y;
    fin >> a >> b >> x >> y;

    int max = abs(a - b);
    int optioni = abs(a - x) + abs(b - y);
    int optionii = abs(a - y) + abs(b - x);
    fout << min(max, min(optioni, optionii));
}