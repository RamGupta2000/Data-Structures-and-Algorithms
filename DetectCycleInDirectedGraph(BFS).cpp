
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclic(int v, vector<int> adj[])
    {
        vector<int> ans;
        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++)
            for (auto it : adj[i])
                indegree[it]++;

        queue<int> q;
        for (int i = 0; i < v; i++)
            if (indegree[i] == 0)
                q.push(i);

        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++;
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        if (count == v)
            return false;
        return true;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
