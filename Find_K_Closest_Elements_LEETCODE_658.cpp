

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x)
    {
        priority_queue<pair<int, int>> p;
        for (int i = 0; i < arr.size(); i++)
        {
            // p.push({abs(x - arr[i]), arr[i]});
            //OR
            pair<int, int> pp(abs(x - arr[i]), arr[i]);

            p.push(pp);

            if (p.size() > k)
                p.pop();
        }
        vector<int> ans;
        while (!p.empty())
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}
