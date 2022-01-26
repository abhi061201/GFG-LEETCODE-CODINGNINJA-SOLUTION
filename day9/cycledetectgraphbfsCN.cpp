#include<bits/stdc++.h>

bool iscycle(int x, int parent, vector<int> adj[], vector<int> &vis){
    vis[x]=1;
    queue<pair<int,int>> q;
    q.push({x,-1});
    while(!q.empty()){
        int temp= q.front().first;
        int par= q.front().second;
        q.pop();
        for(auto it : adj[temp]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,temp});
            }
            else if(it!=par)return true;
        }
    }
    return false;
}




string cycleDetection (vector<vector<int>>& edges, int N, int m)
{
    // Write your code here.
    vector <int> vis(N+1,0);
    vector<int> adj[N+1];
    for( auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    for(int i=1 ;i<=N ;i++){
        if(!vis[i]){
            if(iscycle(i, -1,adj, vis ))return "Yes\n";
        }
    }
    return "No\n";
}
