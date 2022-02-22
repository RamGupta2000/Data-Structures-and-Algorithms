#include <bits/stdc++.h>
using namespace std;

void solve(string input, string output, vector<string>&s)
{
    if (input.empty())
    {
        s.push_back(output);
        return;
    }

    if (isalpha(input[0]))
    {
        string output1 = output;
        string output2 = output;

        output1.push_back(toupper(input[0]));
        output2.push_back(tolower(input[0]));

        input.erase(input.begin() + 0);

        solve(input, output1,s);
        solve(input, output2,s);
    }
    else
    {
        string output1 = output;
        output1.push_back(input[0]);
        
        input.erase(input.begin() + 0);

        solve(input, output1,s);
    }
}

int main()
{
    string input = "aB";
    string output = "";

    vector<string>s;

    solve(input, output, s);

    for( auto i:s )
    {
        cout<<i<<" ";
    }

    return 0;
}