#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool SubsetSum(int wt[], int w, int n)
    {
        int dp[n + 1][w + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < w + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = false;
                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < w + 1; j++)
            {
                if (wt[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j - wt[i - 1]] || dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][w];
    }
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        if (sum % 2 != 0)
            return 0;
        else if (sum % 2 == 0)
            return SubsetSum(arr, sum / 2, n);
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}