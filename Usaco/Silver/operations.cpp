#include <iostream>
using namespace std;

int main()
{
    string s;
    int T;
    cin >> s >> T;
    int tests[T][2];
    int ar[s.size() + 1][3];
    ar[0][0] = 0;
    ar[0][1] = 0;
    ar[0][2] = 0;
    int Cprev = 0, Oprev = 0, Wprev = 0;
    for (int x = 1; x < s.size() + 1; x++)
    {
        ar[x][0] = Cprev;
        ar[x][1] = Oprev;
        ar[x][2] = Wprev;

        if (s[x - 1] == 'C')
        {
            ar[x][0]++;
            Cprev++;
        }
        else if (s[x - 1] == 'O')
        {
            ar[x][1]++;
            Oprev++;
        }
        else
        {
            ar[x][2]++;
            Wprev++;
        }
    }
    for (int x = 0; x < T; x++)
    {
        cin >> tests[x][0] >> tests[x][1];
    }
    for (int x = 0; x < T; x++)
    {
        int Wcount, Ocount, Ccount, start = tests[x][0], end = tests[x][1];
        Ccount = ar[end][0] - ar[start - 1][0];
        Ocount = ar[end][1] - ar[start - 1][1];
        Wcount = ar[end][2] - ar[start - 1][2];

        if (Ccount % 2 == 0 && Ocount % 2 == 1 && Wcount % 2 == 1)
        {
            cout << "Y";
        }
        else if (Ccount % 2 == 1 && Ocount % 2 == 0 && Wcount % 2 == 0)
        {
            cout << "Y";
        }
        else
        {
            cout << "N";
        }
    }
}