#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTime(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int ans = 0;
        int j = 0, src = 0;
        while (n2--)
        {
            for (int i = 0; i < n1; i++)
            {
                if (s1[i] == s2[j])
                {
                    ans += abs(src - i);
                    src = i;
                    j++;
                }
            }
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
        string S1, S2;
        cin >> S1;
        cin >> S2;

        Solution ob;
        cout << ob.findTime(S1, S2) << endl;
    }
    return 0;
}