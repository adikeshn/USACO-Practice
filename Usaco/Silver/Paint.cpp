#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> Fences(N);
    vector<int> forward(N), backward(N), recent(26, -1), n(26, -1);
    for (int x = 0; x < N; x++)
    {
        char a;
        cin >> a;
        Fences[x] = (int)a;
    }
    forward[0] = 1;
    recent[Fences[0] - 65] = 0;
    for (int x = 1; x < N; x++)
    {
        int a = forward[x - 1];
        if (recent[Fences[x] - 65] == -1)
        {
            a++;
        }
        else if ((char)*min_element(Fences.begin() + recent[Fences[x] - 65] + 1, Fences.begin() + x) < Fences[x])
        {
            a++;
        }
        forward[x] = a;
        recent[Fences[x] - 65] = x;
    }
    recent = n;
    reverse(Fences.begin(), Fences.end());
    backward[0] = 1;
    recent[Fences[0] - 65] = 0;
    for (int x = 1; x < N; x++)
    {
        int a = backward[x - 1];
        if (recent[Fences[x] - 65] == -1)
        {
            a++;
        }
        else if ((char)*min_element(Fences.begin() + recent[Fences[x] - 65] + 1, Fences.begin() + x) < Fences[x])
        {
            a++;
        }
        backward[x] = a;
        recent[Fences[x] - 65] = x;
    }
    vector<int> ans;
    for (int x = 0; x < Q; x++)
    {
        int st, end;
        cin >> st >> end;
        st--;
        end--;
        if (end == N - 1 && st == 0)
            ans.push_back(0);
        else if (end == N - 1)
        {
            ans.push_back(forward[st - 1]);
        }
        else if (st == 0)
        {
            ans.push_back(backward[N - end - 2]);
        }
        else
        {
            ans.push_back(forward[st - 1] + backward[N - end - 2]);
        }
    }
    for (int x : ans)
    {
        cout << x << endl;
    }
}