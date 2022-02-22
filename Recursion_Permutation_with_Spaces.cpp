#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output)
{
    if (input.empty())
    {
        cout << output << " ";
        return;
    }
    string output1 = output + "_" + input[0];
    string output2 = output + input[0];

    input.erase(input.begin() + 0);
    
    solve(input, output1);
    solve(input, output2);
}

int main()
{
    string input = "ABC";
    string output = "";

    output.push_back(input[0]);
    input.erase(input.begin() + 0);

    solve(input, output);

    return 0;
}