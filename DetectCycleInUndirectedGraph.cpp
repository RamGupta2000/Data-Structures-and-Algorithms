#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkForCycle(int V, vector<int> adj[], vector<int> vis, int s)
    {
        queue<pair<int, int>> q;
        vis[s] = true;
        q.push({s, -1});

        while (!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();

            for (auto it : adj[node.first])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push({it, node.first});
                }
                else if (node.second != it)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
                if (checkForCycle(V, adj, vis, i))
                    return true;
        }
        return false;
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
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}