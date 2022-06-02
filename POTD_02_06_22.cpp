#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool withinBoundary(int i, int j, int n, vector<vector<int>> &matrix)
    {
        if (i >= n || j >= n || matrix[i][j] == 0)
            return false;
        return true;
    }
    bool solve(vector<vector<int>> &matrix, vector<vector<int>> &ans, int i, int j, int n)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans[i][j] = 1;
            return true;
        }

        if (withinBoundary(i, j, n, matrix))
        {
            ans[i][j] = 1;
            for (int NoOfSteps = 1; NoOfSteps <= matrix[i][j]; NoOfSteps++)
            {
                if (solve(matrix, ans, i, j + NoOfSteps, n))
                    return true;
                if (solve(matrix, ans, i + NoOfSteps, j, n))
                    return true;
            }
            ans[i][j] = false;
        }
        return false;
    }
    vector<vector<int>> ShortestDistance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));

        ans[0][0] = 1;
        if (solve(matrix, ans, 0, 0, n))
            return ans;
        return {{-1}};
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
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.ShortestDistance(matrix);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}