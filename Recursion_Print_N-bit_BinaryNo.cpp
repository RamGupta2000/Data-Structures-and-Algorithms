#include <bits/stdc++.h>
using namespace std;

// Print N-bit BinaryNo having more or equal 1's than 0's for any Prefix

void solve(int n, int ones, int zeros, string output, vector<string>&s)
{
    if (n == 0)
    {
        s.push_back(output);
        return;
    }

    string output1 = output;
    output1.push_back('1');
    solve(n - 1, ones + 1, zeros, output1, s);

    if (ones > zeros)
    {
        string output2 = output;
        output2.push_back('0');
        solve(n - 1, ones, zeros + 1, output2, s);
    }
}

int main()
{
    int n;
    cin >> n;

    int ones = n;
    int zeros = n;

    vector<string> s;
    string output = "";

    solve(n, ones, zeros, output, s);

    for (auto i : s)
    {
        cout << i << endl;
    }

    return 0;
}