#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int N, ans = 0;
vector<int> cows;
void PrintStack(stack<int> in)
{
    while (!in.empty())
    {
        cout << in.top() << " ";
        in.pop();
    }
    cout << endl;
}
void MonoStack()
{
    stack<int> mono_stack, indexStack;
    for (int x = 0; x < cows.size(); x++)
    {
        ans += mono_stack.size();
        cout << ans << endl;

        while (!mono_stack.empty())
        {
            if (mono_stack.top() <= cows[x])
            {
                ans -= (x - indexStack.top()) + 1;
                mono_stack.pop();
                indexStack.pop();
            }
            else
                break;
        }
        cout << ans << endl;

        mono_stack.push(cows[x]);
        indexStack.push(x);
        ans++;
        cout << ans << endl;
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
    cout << ans << endl;

    reverse(cows.begin(), cows.end());
    MonoStack();
    cout << ans;
}