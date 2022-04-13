#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u, v, wt;
    node(int u1, int v1, int wt1)
    {
        u = u1;
        v = v1;
        wt = wt1;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int x, vector<int> &parent)
{
    if (x == parent[x])
        return x;

    return parent[x] = findPar(parent[x], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<int> rank(n, 0);

    int cost = 0;
    vector<pair<int, int>> mst;

    for (auto it : edges)
    {
        if (findPar(it.u, parent) != findPar(it.v, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});

            unionn(it.u, it.v, parent, rank);
        }
    }

    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << "<->" << it.second << endl;
    return 0;
}