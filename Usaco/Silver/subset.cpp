#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
const int SIG = 18;
bool works[SIG] = {false}, pair_Works[SIG][SIG] = {true};
int main()
{
    string first, second;
    cin >> first >> second;
    int count1[SIG] = {}, count2[SIG] = {};
    for (int x = 0; x < first.size(); x++)
    {
        count1[first[x] - 'a']++;
    }
    for (int x = 0; x < second.size(); x++)
    {
        count2[second[x] - 'a']++;
    }
    for (int x = 0; x < SIG; x++)
    {
        if (count1[x] != 0 && count2[x] != 0)
        {
            if (count1[x] == count2[x])
                works[x] = true;
        }
    }
    for (int x = 0; x < SIG; x++)
    {
        for (int y = x; y < SIG; y++)
        {
            if (works[x] && works[y])
            {
                pair_Works[x][y] = true;
                pair_Works[y][x] = true;
                string a, b;
                for (char z : first)
                {
                    if (z == x + 'a' || z == y + 'a')
                    {
                        a.push_back(z);
                    }
                }
                for (char z : second)
                {
                    if (z == x + 'a' || z == y + 'a')
                    {
                        b.push_back(z);
                    }
                }
                if (a != b)
                {
                    pair_Works[x][y] = false;
                    pair_Works[y][x] = false;
                }
            }
        }
    }
    int q;
    cin >> q;
    vector<char> ans(q, 'Y');
    for (int x = 0; x < q; x++)
    {
        string quere;
        cin >> quere;
        for (int y = 0; y < quere.size(); y++)
        {
            if (!works[quere[y] - 'a'])
            {
                ans[x] = ('N');
            }
        }
        if (ans[x] == 'Y')
        {
            for (int y = 0; y < quere.size(); y++)
            {
                for (int z = y; z < quere.size(); z++)
                {
                    if (!pair_Works[quere[y] - 'a'][quere[z] - 'a'])
                        ans[x] = 'N';
                }
            }
        }
    }
    for (int x = 0; x < q; x++)
    {
        cout << ans[x];
    }
}