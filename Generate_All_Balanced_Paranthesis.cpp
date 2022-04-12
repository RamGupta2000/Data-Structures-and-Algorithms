#include <bits/stdc++.h>
using namespace std;

// Generate all balanced paranthesis for n

void solve(int open, int close, string output, vector<string> &s)
{
    if (open == 0 && close == 0)
    {
        s.push_back(output);
        return;
    }

    if (open != 0)
    {
        string output1 = output;

        output1.push_back('(');

        solve(open-1, close, output1, s);
    }

    if (open < close)
    {
        string output2 = output;

        output2.push_back(')');

        solve(open, close-1, output2, s);
    }
}

int main()
{
    int n;
    cin >> n;

    int open = n;
    int close = n;

    vector<string> s;
    string output = "";

    solve(open, close, output, s);

    for (auto i : s)
    {
        cout << i << endl;
    }

    return 0;
}