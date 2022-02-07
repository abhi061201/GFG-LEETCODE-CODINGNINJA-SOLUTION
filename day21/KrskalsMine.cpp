#include <bits/stdc++.h>
using namespace std;
int par(int x, vector<int> &parent, vector<int> &rank)
{
    if (parent[x] == x)
        return x;
    else
    {
        return parent[x] = par(parent[x], parent, rank);
    }
}
void unite(int x, int y, vector<int> &parent, vector<int> &rank)
{

    if (rank[x] < rank[y])
    {
        parent[x] = y;
    }
    else if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else if (rank[x] == rank[y])
    {
        rank[x]++;
        parent[y] = x;
    }
}

void kruskals(int &cost, vector<vector<int>> adj[], int n)
{
    vector<pair<int, pair<int, int>>> v;
    vector<int> vis(n,0);
    for (int i = 0; i < n; i++)
    {   if(!vis[i])
        for (auto it : adj[i])
        {
            v.push_back({it[1], {i,it[0]}});
        }
        vis[i]=1;
    }
    vector<int> parent(n, 0);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    sort(v.begin(), v.end());

    for (auto it : v)
    {
        int u = it.second.first;
        int v = it.second.second;
        u= par(u,parent,rank);
        v=par(v, parent, rank);

        if (u !=v )
        {
            unite(u, v, parent, rank);
            cost += it.first;
        }
    }
}

int main()
{

    cout << "Enter the number of nodes and edges in your Graph\n";
    int n, e;
    cin >> n >> e;
    cout << "Enter the edges with their respective weights\n";
    vector<vector<int>> adj[n+1];
    for (int i = 0; i < e; i++)
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
    int cost = 0;
    kruskals(cost, adj, n+1);
    cout << cost;

    return 0;
}
