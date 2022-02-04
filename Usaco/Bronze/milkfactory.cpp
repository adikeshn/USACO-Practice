#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
    ifstream input("factory.in");
    ofstream output("factory.out");
    int N, index = 0;
    input >> N;
    int walkways[N - 1][2];
    for (int x = 0; x < N - 1; x++)
    {
        input >> walkways[index][0] >> walkways[index][1];
        index++;
    }
    int next;
    for (int x = 1; x < N + 1; x++)
    {
        int count = 0;
        for (int y = 1; y < N + 1; y++)
        {
            if (x != y)
            {
                next = y;
                int connect = y;
                for (int z = 0; z < N - 1; z++)
                {
                    if (walkways[z][0] == connect)
                    {
                        if (walkways[z][1] == x)
                        {
                            count++;
                            z = N - 1;
                        }
                        else
                        {
                            connect = walkways[z][1];
                            z = -1;
                        }
                    }
                }
            }
        }
        if (count == N - 1)
        {
            output << x << endl;
            return 0;
        }
    }
    output << "-1" << endl;
    return 0;
}