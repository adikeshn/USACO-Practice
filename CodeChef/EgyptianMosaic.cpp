#include <iostream>
#include <vector>

using namespace std;

void printarray(vector<vector<char>> arr, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

vector<vector<char>> fillMosaic(int width, int height)
{
    vector<vector<char>> mosaic;
    vector<char> temp;
    for (int x = 0; x < width; x++)
    {
        temp.push_back('.');
    }
    temp[width / 2] = '#';
    mosaic.push_back(temp);
    for (int x = 1; x < height; x++)
    {
        vector<char> temp;
        for (int y = 0; y < width; y++)
        {
            int n, ne, nw;
            if (mosaic[x - 1][y] == '.')
            {
                n = 0;
            }
            else
                n = 1;
            if (y - 1 < 0 || mosaic[x - 1][y - 1] == '.')
            {
                nw = 0;
            }
            else
                nw = 1;
            if (y + 1 >= width || mosaic[x - 1][y + 1] == '.')
            {
                ne = 0;
            }
            else
                ne = 1;

            if ((nw == 1 && ne == 1 && n == 1) || (nw == 0 && ne == 0 && n == 0))
            {
                temp.push_back('.');
            }
            else
                temp.push_back('#');
        }
        mosaic.push_back(temp);
    }
    return mosaic;
}

int main()
{
    int tests, width, height;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        cin >> width >> height;
        printarray(fillMosaic(width, height), width, height);
    }
}