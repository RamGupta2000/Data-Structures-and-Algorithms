
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution
{
public:
    vector<int> topK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            p.push({i->second, i->first});
            if (p.size() > k)
                p.pop();
        }
        vector<int> ans;
        while (!p.empty())
        {
            ans.push_back(p.top().second);
            p.pop();
        }
        reverse(ans.begin(), ans.end());
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
        for (auto &i : nums)
            cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}