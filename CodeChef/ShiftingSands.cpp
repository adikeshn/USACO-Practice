#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<vector<int>> moveNorth(vector<vector<int>> &board)
{
    bool ar[4][4] = {false};
    for (int y = 1; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (board[y][x] != 0)
            {
                if (board[y - 1][x] == board[y][x] && !ar[y - 1][x])
                {
                    board[y - 1][x] += board[y][x];
                    board[y][x] = 0;
                    ar[y - 1][x] = true;
                }
                if (board[y - 1][x] == 0)
                {
                    int n = y - 1;
                    while (board[n][x] == 0 && n != 0)
                    {
                        n--;
                    }

                    if (board[n][x] == board[y][x] && !ar[n][x])
                    {
                        board[n][x] += board[y][x];
                        board[y][x] = 0;
                        ar[n][x] = true;
                    }
                    else
                    {
                        if (board[n][x] == 0)
                        {
                            board[n][x] = board[y][x];
                            board[y][x] = 0;
                        }
                        else
                        {
                            board[n + 1][x] = board[y][x];
                            board[y][x] = 0;
                        }
                    }
                }
            }
        }
    }
    return board;
}

vector<vector<int>> moveSouth(vector<vector<int>> &board)
{
    bool ar[4][4] = {false};
    for (int y = 2; y >= 0; y--)
    {
        for (int x = 0; x < 4; x++)
        {
            if (board[y][x] != 0)
            {
                if (board[y + 1][x] == board[y][x] && !ar[y + 1][x])
                {
                    board[y + 1][x] += board[y][x];
                    board[y][x] = 0;
                    ar[y + 1][x] = true;
                }
                if (board[y + 1][x] == 0)
                {
                    int n = y + 1;
                    while (board[n][x] == 0 && n != 3)
                    {
                        n++;
                    }
                    if (board[n][x] == board[y][x] && !ar[n][x])
                    {
                        board[n][x] += board[y][x];
                        board[y][x] = 0;
                        ar[n][x] = true;
                    }
                    else
                    {
                        if (board[n][x] == 0)
                        {
                            board[n][x] = board[y][x];
                            board[y][x] = 0;
                        }
                        else
                        {
                            board[n - 1][x] = board[y][x];
                            board[y][x] = 0;
                        }
                    }
                }
            }
        }
    }
    return board;
}

vector<vector<int>> moveEast(vector<vector<int>> &board)
{
    bool ar[4][4] = {false};
    for (int x = 2; x >= 0; x--)
    {
        for (int y = 0; y < 4; y++)
        {
            if (board[y][x] != 0)
            {
                if (board[y][x + 1] == board[y][x] && !ar[y][x + 1])
                {
                    board[y][x + 1] += board[y][x];
                    board[y][x] = 0;
                    ar[y][x + 1] = true;
                }
                if (board[y][x + 1] == 0)
                {
                    int n = x + 1;
                    while (board[y][n] == 0 && n != 3)
                    {
                        n++;
                    }
                    if (board[y][n] == board[y][x] && !ar[y][n])
                    {
                        board[y][n] += board[y][x];
                        board[y][x] = 0;
                        ar[y][n] = true;
                    }
                    else
                    {
                        if (board[y][n] == 0)
                        {
                            board[y][n] = board[y][x];
                            board[y][x] = 0;
                        }
                        board[y][n - 1] = board[y][x];
                        board[y][x] = 0;
                    }
                }
            }
        }
    }
    return board;
}

vector<vector<int>> moveWest(vector<vector<int>> &board)
{
    int ar[4][4] = {false};
    for (int x = 1; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (board[y][x] != 0)
            {
                if (board[y][x - 1] == board[y][x] && !ar[y][x - 1])
                {
                    board[y][x - 1] += board[y][x];
                    board[y][x] = 0;
                    ar[y][x - 1] = true;
                }
                if (board[y][x - 1] == 0)
                {
                    int n = x - 1;
                    while (board[y][n] == 0 && n != 0)
                    {
                        n--;
                    }
                    if (board[y][n] == board[y][x] && !ar[y][n])
                    {
                        board[y][n] += board[y][x];
                        board[y][x] = 0;
                        ar[y][n] = true;
                    }
                    else
                    {
                        if (board[y][n] == 0)
                        {
                            board[y][n] = board[y][x];
                            board[y][x] = 0;
                        }
                        else
                        {
                            board[y][n + 1] = board[y][x];
                            board[y][x] = 0;
                        }
                    }
                }
            }
        }
    }
    return board;
}

vector<vector<int>> shiftingSands(vector<vector<int>> board, vector<string> moves)
{
    for (string s : moves)
    {
        if (s.compare("E") == 0)
            moveEast(board);
        else if (s.compare("W") == 0)
            moveWest(board);
        else if (s.compare("S") == 0)
            moveSouth(board);
        else
            moveNorth(board);
    }
    return board;
}

// Do not modify below this line
vector<string> tokenize(string s)
{
    vector<string> tokens;
    stringstream ss(s);
    string word;

    while (ss >> word)
        tokens.push_back(word);

    return tokens;
}

int main()
{
    string s;
    int t;

    getline(cin, s);
    t = stoi(s);

    for (int i = 0; i < t; i++)
    {
        vector<vector<int>> board;

        for (int j = 0; j < 4; j++)
        {
            vector<int> vector_row;
            getline(cin, s);
            vector<string> vector_row_str = tokenize(s);
            for (int k = 0; k < 4; k++)
                vector_row.push_back(stoi(vector_row_str[k]));

            board.push_back(vector_row);
        }

        vector<string> moves;
        getline(cin, s);
        moves = tokenize(s);
        vector<vector<int>> output = shiftingSands(board, moves);

        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << output[j][k] << " ";
            }
            cout << endl;
        }
    }
}