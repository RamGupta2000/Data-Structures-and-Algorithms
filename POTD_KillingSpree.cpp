#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int killinSpree(long long int n)
    {
        long long count = 0;
        long long r = 1;
        while (n >= r * r)
        {
            count++;
            n -= r * r;
            r++;
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout << ans << "\n";
    }
    return 0;
}
