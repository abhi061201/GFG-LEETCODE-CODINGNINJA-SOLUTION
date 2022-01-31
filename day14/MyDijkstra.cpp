#include <bits/stdc++.h>
using namespace std;

void dijkstra(int src, vector<pair<int, int>> adj[], vector<int> &dist)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[src]=0;
    pq.push({0,1});
    while(!pq.empty()){
        int d= pq.top().first;
        int node= pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            int nnode= it.first;
            int dnode= it.second;
            
            if(dist[nnode] > d+dnode){
                   dist[nnode] = d+dnode;
                   pq.push({dist[nnode] ,nnode});
            }

        }
    }


}

int main()
{

    cout << "Enter the no. of nodes and edes \n ";
    int n, e;
    cin >> n >> e;
    cout << "Enter the adjacency of nodes\n";
    vector<pair<int, int>> adj[n + 1];
    bool visited[n] = {false};
    int u, v, w;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(n + 1, INT_MAX);
    int src = 1;
    dijkstra(src, adj, dist);

    for(int i=1 ; i<=n ;i++){
        cout<< i<<" : "<<dist[i]<<" , ";
    }

    return 0;
}
