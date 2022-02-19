#include <bits/stdc++.h>
using namespace std;

string toh(string s)
{
    if (s.empty())
    {
        return "";
    }
    char c = s[0];
    string ans = toh( s.substr(1) );
    if( '1'==c )
    {
        return ans+c;
    }
    return c+ans;
}
int main()
{
    cout<<toh("xa1sx1x1111s1k11x");
    return 0;
}