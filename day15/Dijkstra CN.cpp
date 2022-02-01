#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int s) {
    // Write your code here.
    vector <int> distto(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    pq.push({0,s});
    distto[s]=0;
    vector<pair<int,int>> adj[V];
    for(auto it :vec){
        int u=it[0];
        int v= it[1];
        int w= it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    while(!pq.empty()){
        int dist= pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int edgeweight= it.second;
            int nodeto=     it.first;
            
            if(distto[nodeto] >edgeweight +dist){
         		distto[nodeto] =edgeweight +dist;
                pq.push({distto[nodeto],nodeto});
            }
        }
       
    }
    return distto;
    
}
