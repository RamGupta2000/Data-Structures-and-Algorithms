
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs_util(vector<int> &vis, vector<int> &dfs, vector<int> adj[], auto i, int v)
    {
        if (vis[i])
            return;

        vis[i] = true;
        dfs.push_back(i);
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                dfs_util(vis, dfs, adj, it, v);
            }
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[])
    {
        vector<int> vis(v, false);
        vector<int> dfs;

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                dfs_util(vis, dfs, adj, i, v);
        }
        return dfs;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}