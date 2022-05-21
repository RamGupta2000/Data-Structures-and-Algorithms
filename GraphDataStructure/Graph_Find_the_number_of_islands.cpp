
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid, int n, int m)
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        if (grid[i][j] == '0')
            return;

        if (!vis[i][j])
        {
            vis[i][j] = 1;
            dfs(i - 1, j - 1, vis, grid, grid.size(), grid[0].size());
            dfs(i - 1, j, vis, grid, grid.size(), grid[0].size());
            dfs(i - 1, j + 1, vis, grid, grid.size(), grid[0].size());
            dfs(i, j - 1, vis, grid, grid.size(), grid[0].size());
            dfs(i, j + 1, vis, grid, grid.size(), grid[0].size());
            dfs(i + 1, j - 1, vis, grid, grid.size(), grid[0].size());
            dfs(i + 1, j, vis, grid, grid.size(), grid[0].size());
            dfs(i + 1, j + 1, vis, grid, grid.size(), grid[0].size());
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        // int vis[501][501] = {0};
        vector<vector<int>> vis(501, vector<int>(501, 0));

        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, vis, grid, grid.size(), grid[0].size());
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}