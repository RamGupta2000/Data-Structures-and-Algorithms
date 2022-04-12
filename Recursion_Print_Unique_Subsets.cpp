#include <bits/stdc++.h>
using namespace std;

/* 
    You can also use set in place of vector
    Set only stores unique elements
*/

void solve(string input, string output, vector<string> &ans, int i)
{
    if (i >= input.size())
    {
        if (ans.end() == find(ans.begin(), ans.end(), output))
        {
            ans.push_back(output);
        }
        return;
    }
    solve(input, output, ans, i + 1);

    char element = input[i];
    output.push_back(element);

    solve(input, output, ans, i + 1);
}

int main()
{
    string input = "aab";
    string output = "";

    vector<string> ans;

    solve(input, output, ans, 0);

    // To print in lexicographical order 
    // sort( ans.begin(), ans.end() );

    for (auto i : ans)
    {
        cout << "->" << i;
    }
    return 0;
}