#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1010][1010];
    int knapSack2(int W, int wt[], int val[], int n)
    {
        if (n == 0 || W == 0)
            return 0;
        if (dp[W][n] != -1)
            return dp[W][n];

        int ans = knapSack2(W, wt, val, n - 1);
        if (W - wt[n - 1] >= 0)
            ans = max(ans, knapSack2(W - wt[n - 1], wt, val, n - 1) + val[n - 1]);
        return dp[W][n] = ans;
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        memset(dp, -1, sizeof(dp));
        return knapSack2(W, wt, val, n);
    }
};