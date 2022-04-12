#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7] = {6, 5, 3, 2, 8, 10, 9};
    int n = 7;
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
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

    for (auto i : ans)
        cout << i << " ";
    return 0;
}