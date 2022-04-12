#include <bits/stdc++.h>
using namespace std;

void DeleteMiddleOfStack(stack<int> &s, int mid)
{
    if (mid == s.size())
    {
        s.pop();
        return;
    }
    int top = s.top();
    s.pop();
    DeleteMiddleOfStack(s,mid);
    s.push(top);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(55);
    s.push(6);

    int mid = s.size() / 2 + 1;

    DeleteMiddleOfStack(s, mid);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}