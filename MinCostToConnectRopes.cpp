
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<long long>> p;
        for (long i = 0; i < n; i++)
        {
            p.push(arr[i]);
        }

        while (p.size() != 1)
        {

            long long x = p.top();
            p.pop();
            long long y = p.top();
            p.pop();

            sum += x + y;
            p.push(x + y);
        }
        return sum;
    }
};

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
