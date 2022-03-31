
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nearlySorted(int arr[], int num, int K)
    {
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < num; i++)
        {
            pq.push(arr[i]);
            if (pq.size() > K)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int num, K;
        cin >> num >> K;

        int arr[num];
        for (int i = 0; i < num; ++i)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res = ob.nearlySorted(arr, num, K);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }

    return 0;
}
