#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream input("gymnastics.in");
    ofstream output("gymnastics.out");
    int K, N, pairs = 0;
    input >> K >> N;
    int cows[K][N];
    for (int x = 0; x < K; x++)
    {
        for (int y = 0; y < N; y++)
        {
            input >> cows[x][y];
        }
    }
    for (int x = 1; x < N + 1; x++)
    {
        for (int y = 1; y < N + 1; y++)
        {
            if (x != y)
            {
                bool valid = true;
                for (int z = 0; z < K; z++)
                {
                    int index1 = 0, index2 = 0;
                    for (int u = 0; u < N; u++)
                    {
                        if (cows[z][u] == x)
                        {
                            index1 = u;
                        }
                        else if (cows[z][u] == y)
                        {
                            index2 = u;
                        }
                    }
                    if (index2 < index1)
                    {
                        valid = false;
                    }
                }
                if (valid == true)
                {
                    pairs++;
                }
            }
        }
    }
    cout << pairs;
    output << pairs << endl;
    return 0;
}