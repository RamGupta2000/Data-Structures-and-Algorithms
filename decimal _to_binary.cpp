#include <bits/stdc++.h>
using namespace std;

string removezero( string s )
{
    int i=0;
    while( s[i] =='0' )
    {
        i++;
    }
    s.erase(0,i);
    return s;
}
vector<string> generate(int N)
{
    vector<string>s;
    for (int i = 1; i <= N; i++)
    {
        string s1=bitset<50>(i).to_string();

        s.push_back( removezero(s1) );
    }
    return s;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ans = generate(n);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}