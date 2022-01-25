#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> dfs_helper(int x, int parent, vector<int> adj[], int vis[])
{
    vis[x] = 1;
    v.push_back(x);
    for (auto it : adj[x])
    {
        if (!vis[it])
        {
            dfs_helper(it, x, adj, vis);
        }
    }
    return v;
}
vector<int> dfs(int x, vector<int> adj[])
{
    int vis[x + 1] = {0};
    return dfs_helper(0, -1, adj, vis);
}

int main()
{
    int n, e;
    cout << "Enter the no. of nodes and no. of edges in your graph \n";
    cin >> n >> e;
    vector<int> adj[n];
    cout << "Enter the adjacency of your nodes\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool visited[n];
    memset(visited, false, sizeof(visited));
    cout << "Your dfs of graph is : \n";
    vector <int> x= dfs(n, adj);
    for(auto it : x)cout<<it<<" , ";


    return 0;
}
