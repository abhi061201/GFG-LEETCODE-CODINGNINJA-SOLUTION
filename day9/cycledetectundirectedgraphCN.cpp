#include <bits/stdc++.h>

bool iscycle(int x, int parent , vector <int>adj[], vector<int> &vis){
    vis[x]= 1;
    
    for(auto nbr :adj[x] ){
        if(!vis[nbr]){
            vis[nbr]=1;
            if(iscycle(nbr,x, adj,vis))return true;
        }
        else if(nbr !=parent){return true;}
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
       vector <int> vis(n+1,0);
    	vector <int> adj[n+1];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
         adj[it[1]].push_back(it[0]);
    }
    for(int i=1 ;i<=n ;i++ ){
       if(!vis[i]){
           if(iscycle( i, -1, adj, vis))return "Yes";
       }
    }
    return "No";
}
