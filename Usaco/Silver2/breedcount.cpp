#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct cowNums
{
    int one, two, three;
};
vector<cowNums> arr(100001);

int main()
{
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int N, Q;
    fin >> N >> Q;
    cowNums n = {0, 0, 0};
    for (int x = 0; x < N; x++)
    {
        int y;
        fin >> y;
        if (y == 1)
            n.one++;
        else if (y == 2)
            n.two++;
        else
            n.three++;
        arr[x] = n;
    }

    for (int x = 0; x < Q; x++)
    {
        int start, end;
        fin >> start >> end;
        if (start != 1)
        {
            fout << arr[end - 1].one - arr[start - 2].one << " "
                 << arr[end - 1].two - arr[start - 2].two << " " << arr[end - 1].three - arr[start - 2].three << endl;
        }
        else
        {
            fout << arr[end - 1].one << " "
                 << arr[end - 1].two << " " << arr[end - 1].three << endl;
        }
    }
}