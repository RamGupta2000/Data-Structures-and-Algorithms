#include <bits/stdc++.h>
using namespace std;

void SortedInsert(stack<int> &s, int top_value)
{
    if (s.size() == 0 || s.top() < top_value)
    {
        s.push(top_value);
        return;
    }
    int greater_value = s.top();
    s.pop();
    SortedInsert(s, top_value);
    s.push(greater_value);
}

void sortStack(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int top_value = s.top();
    s.pop();
    sortStack(s);
    SortedInsert(s, top_value);
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(2);
    s.push(5);
    s.push(1);
    s.push(1);
    s.push(3);
    s.push(4);

    sortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}