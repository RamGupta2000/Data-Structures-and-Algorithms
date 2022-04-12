#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodestring(string &s, int &i)
    {
        string result;
        while (i < s.length() && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int k = 0;
                while (i < s.length() && isdigit(s[i]))
                {
                    k = k * 10 + s[i++] - '0';
                }
                i++;
                string res = decodestring(s, i);
                while (k-- > 0)
                {
                    result += res;
                }
                i++;
            }
            else
            {
                result += s[i++];
            }
        }
        return result;
    }

    string decodedString(string s)
    {
        int i = 0;
        return decodestring(s, i);
    }
};

int main()
{
    string s;
    cin >> s;

    Solution ob;
    cout << ob.decodedString(s) << "\n";
    return 0;
}
