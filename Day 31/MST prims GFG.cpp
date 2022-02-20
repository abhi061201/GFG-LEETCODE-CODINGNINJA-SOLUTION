// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        int ans=0;
        vector<int>vis(n,-0);
        vector<int>dist(n,INT_MAX);
        prims(0,adj,vis,dist);
        for(auto it : dist){
            ans+=it;
        }
        return ans;
        
        
    }
    void prims(int x,vector<vector<int>> adj[], vector<int>&vis, vector<int>&dist){
        dist[x]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,x});
        while(!pq.empty()){
            int cur_node= pq.top().second;
            int cur_dist=pq.top().first;
            vis[cur_node]=1;
            pq.pop();
            for(auto it : adj[cur_node]){
               if(!vis[it[0]] && dist[it[0]] >it[1]){
                   dist[it[0]]= it[1];
                   pq.push({it[1],it[0]});
               }
            }
            
            
        }
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
