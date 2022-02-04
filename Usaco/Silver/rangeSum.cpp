#include <iostream>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    int ar[N];
    int sums[N];
    int queries[Q][2];
    for (int x = 0; x < N; x++)
    {
        cin >> ar[x];
        if (x != 0)
        {
            sums[x] = sums[x - 1] + ar[x];
        }
        else
        {
            sums[0] = ar[0];
        }
    }
    for (int x = 0; x < Q; x++)
    {
        cin >> queries[x][0];
        cin >> queries[x][1];
    }
    for (int x = 0; x < Q; x++)
    {
        int answer = (sums[queries[x][1] - 1] - (sums[queries[x][0] - 1]));
        if (queries[x][0] == 0)
        {
            cout << sums[queries[x][1] - 1] << endl;
        }
        else
        {
            cout << answer << endl;
        }
    }
}
