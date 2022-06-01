#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> &ans, int N, int n, int src, int dest, int help)
    {
        if (N == 0)
            return;

        solve(ans, N - 1, n, src, help, dest);
        ans.push_back({src, dest});
        solve(ans, N - 1, n, help, dest, src);
    }
    vector<int> shiftPile(int N, int n)
    {
        vector<vector<int>> ans;
        solve(ans, N, n, 1, 3, 2);
        return ans[n - 1];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, n;
        cin >> N >> n;

        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}