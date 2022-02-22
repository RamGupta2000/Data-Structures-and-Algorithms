#include <bits/stdc++.h>
using namespace std;

void insertingTopAtLast(stack<int>&s, int top)
{
    if( s.empty() )
    {
        s.push(top);
        return;
    }
    int new_top = s.top();
    s.pop();
    insertingTopAtLast(s,top);
    s.push(new_top);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    reverseStack(s);

    insertingTopAtLast(s,top);
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(5);
    s.push(4);
    s.push(1);
    s.push(2);

    reverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}