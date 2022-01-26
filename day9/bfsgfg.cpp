
#include <bits/stdc++.h>

void bfs(int x, vector<vector<int>> &adj, vector <int>&vis, vector <int> &v ){
    vis[x]=1;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int temp= q.front();
        q.pop();
        v.push_back(temp);
       for(int it=0 ;it<adj.size();it++){
            if(!vis[it] && adj[temp][it]==1){
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    vector<int>vis(V,0);
    vector<int> v;
  vector<vector<int>> adj(V,vector<int>(V,0));
    for(auto it : edges){
        adj[it.first][it.second]=1;
        adj[it.second][it.first]=1;
    }
    for(int i=0 ;i<V ;i++){
        if(!vis[i])bfs(i, adj,vis, v);
    }
    return v;
}
