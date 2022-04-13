
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(v, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        dis[S] = 0;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                if (it[1] + distance < dis[it[0]])
                {
                    dis[it[0]] = it[1] + distance;
                    pq.push({it[1] + distance, it[0]});
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            ans.push_back(dis[i]);
        }
        return ans;
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
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
