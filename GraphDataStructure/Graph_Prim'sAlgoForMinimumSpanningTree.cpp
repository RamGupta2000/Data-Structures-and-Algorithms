#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> key(v, INT_MAX);
        vector<int> mst(v, false);
        vector<int> parent(v, -1);

        key[0] = 0;
        parent[0] = -1;

        for (int i = 0; i < v - 1; i++)
        {
            int min = INT_MAX;
            int u;
            for (int j = 0; j < v; j++)
            {
                if (key[j] < min && mst[j] == false)
                {
                    min = key[j];
                    u = j;
                }
            }
            mst[u] = true;
            for (auto it : adj[u])
            {
                int edge = it[0];
                int weight = it[1];
                if (mst[edge] == false && weight < key[edge])
                {
                    key[edge] = weight;
                    parent[edge] = u;
                }
            }
        }
        int totalweight = 0;
        for (int i = 0; i < v; i++)
        {
            totalweight += key[i];
        }
        return totalweight;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
