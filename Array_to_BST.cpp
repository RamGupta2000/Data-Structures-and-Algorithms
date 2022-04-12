
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> nums, vector<int> &ans, int s, int e)
    {
        if (s > e)
        {
            return;
        }
        int mid = s + (e - s) / 2;
        ans.push_back(nums[mid]);
        if( mid != s )
            solve(nums, ans, s, mid-1);
        if( mid != e )
            solve(nums, ans, mid+1, e);

    }
    vector<int> sortedArrayToBST(vector<int> &nums)
    {
        vector<int> ans;
        solve(nums, ans, 0, nums.size()-1);
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        vector<int> ans = obj.sortedArrayToBST(nums);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}