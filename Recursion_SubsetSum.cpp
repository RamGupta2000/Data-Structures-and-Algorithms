
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> arr, int N, int i, vector<int> &ans, int output)
    {
        if (i >= arr.size())
        {
            ans.push_back(output);
            return;
        }
        solve(arr, N, i + 1, ans, output);
        int element = arr[i];

        output += element;
        solve(arr, N, i + 1, ans, output);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {

        vector<int> ans;
        int output = 0;
        solve(arr, N, 0, ans, output);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}