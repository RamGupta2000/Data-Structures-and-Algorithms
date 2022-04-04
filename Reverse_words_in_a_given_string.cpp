
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "";
        string cur = "";
        vector<string> v;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '.')
            {
                v.push_back(cur);
                cur = "";
            }
            else
                cur += s[i];
        }
        v.push_back(cur);

        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans += v[i];
            if (i != 0)
                ans += '.';
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}