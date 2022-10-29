#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

long long N, ans = 0;
vector<int> cows;
void PrintStack(stack<int> in, int x)
{
    while (!in.empty())
    {
        cout << "(" << in.top() + 1 << ", " << x + 1 << ")"
             << "    ";
        in.pop();
    }
    cout << endl;
}
void MonoStack()
{
    stack<int> mono_stack;
    for (int x = 0; x < cows.size(); x++)
    {
        while (!mono_stack.empty() && cows[mono_stack.top()] < cows[x])
            mono_stack.pop();
        if (!mono_stack.empty())
            ans += (x - mono_stack.top()) + 1;
        mono_stack.push(x);
    }
}

int main()
{
    cin >> N;
    for (int x = 0; x < N; x++)
    {
        int y;
        cin >> y;
        cows.push_back(y);
    }
    MonoStack();

    reverse(cows.begin(), cows.end());
    MonoStack();
    cout << ans;
}