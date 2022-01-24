#include <bits/stdc++.h>
using namespace std;

void dfs(int x, vector<int> adj[], bool visited[])
{

    if (visited[x])
        return;
    cout << x << ",";
    visited[x] = true;
    for(int nbr: adj[x]){
        dfs(nbr,adj,visited);
    }

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
    cout<<"Your dfs of graph is : \n";
    dfs(3,adj,visited);

    return 0;
}
