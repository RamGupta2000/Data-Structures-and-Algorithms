#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output)
{
    // static int i=1;   To see empty subset
    if (input.empty())
    {
        // cout << output<<i++ << " ";
        cout << "->"<< output;
        return;
    }
    string output1 = output;
    string output2 = output;

    output2.push_back(input[0]);

    input.erase(input.begin() + 0);
    
    solve(input, output1);
    solve(input, output2);
}

int main()
{
    string input = "abc";
    string output = "";

    solve(input, output);

    return 0;
}