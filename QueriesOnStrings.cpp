#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> SolveQueris(string str, vector<vector<int>> Query)
    {
        vector<int> ans;
        int n = Query.size();
        for (int i = 0; i < n; i++)
        {
            int l = Query[i][0];
            int r = Query[i][1];
            int count = 0;
            set<char> s;
            for (int i = l; i <= r; i++)
            {
                s.insert(str[i - 1]);
            }
            ans.push_back(s.size());
        }
        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        int q;
        cin >> q;
        vector<vector<int>> Query;
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            Query.push_back({l, r});
        }
        Solution obj;
        vector<int> ans = obj.SolveQueris(str, Query);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}