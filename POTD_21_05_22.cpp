#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> farNumber(int n, vector<int> arr)
    {

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            for (int j = n - 1; j > i; j--)
            {
                if (x > arr[j])
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
            cin >> Arr[i];
        Solution obj;
        vector<int> answer = obj.farNumber(N, Arr);
        for (auto i : answer)
            cout << i << " ";
        cout << endl;
    }
}