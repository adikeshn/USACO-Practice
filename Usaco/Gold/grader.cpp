#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// solve test case
string solveTC()
{
    int N;
    string ans = "";
    cin >> N;
    vector<int> a;
    int ai;
    for (int i = 0; i < N; i++)
    {
        cin >> ai;
        a.push_back(abs(ai) % 10);
    }
    bool dp[10];
    for (int i = 0; i < 10; i++)
        dp[i] = false;
    vector<int> newDP;
    bool added = false;
    for (int i : a)
    {
        if (i == 3)
        {
            ans += "Y";
            added = true;
        }
        newDP.push_back(i);
        for (int j = 0; j < 10; j++)
        {
            if (dp[j])
            {
                newDP.push_back((j * i) % 10);
                if (!added && (j * i) % 10 == 3)
                {
                    ans += "Y";
                    added = true;
                }
            }
        }
        if (!added)
            ans += "N";
        for (int j : newDP)
            dp[j] = true;
        newDP.clear();
        added = false;
    }

    return ans;
}

int main()
{
    // generate test cases
    freopen("producingThrees.in", "w", stdout);
    cout << 10 << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << 10 << endl;
        for (int j = 0; j < 10; j++)
            cout << rand() << " ";
        cout << endl;
    }
    for (int i = 0; i < 200; i++)
    {
        cout << 100 << endl;
        for (int j = 0; j < 100; j++)
            cout << rand() << " ";
        cout << endl;
    }
    for (int i = 0; i < 200; i++)
    {
        cout << 1000 << endl;
        for (int j = 0; j < 1000; j++)
            cout << rand() << " ";
        cout << endl;
    }
    int r;
    for (int i = 0; i < 200; i++)
    {
        r = rand();
        cout << r << endl;
        for (int j = 0; j < r; j++)
            cout << (rand() * rand() / 2) - 268419073 << " ";
        cout << endl;
    }

    cout << 1000000 << endl;
    for (int j = 0; j < 1000000; j++)
        cout << (rand() - 16383) << " ";
    cout << endl;

    freopen("producingThrees.in", "r", stdin);
    freopen("CON", "w", stdout);
    int T;
    cin >> T;
    vector<string> ans;
    while (T--)
        ans.push_back(solveTC());
    // check solutions
    cout << "Using the file producingThrees.in, create an output file producingThrees.out with the correct output. Type when you code is done. Remember to have a new line for every test case." << endl;


    string waiting;
    freopen("CON", "r", stdin);
    cin >> waiting;
    freopen("producingThrees.out", "r", stdin);
    bool correct = true;
    string s2;
    for (string s : ans)
    {
        cin >> s2;
        if (s != s2)
            correct = false;
    }
    if (!correct)
        cout << "Sorry, you did not get the correct output" << endl;
    else
        cout << "flag{n1c3_w0rk_8329}" << endl;
}