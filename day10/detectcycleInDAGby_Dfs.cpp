// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
   
   bool iscyclehelper(int x,vector<int> adj[], vector<int>&vis, vector <int>&dfs ){
       vis[x]=1;
       dfs[x]=1;
       for(auto it : adj[x]){
           if(!vis[it]){
               vis[it]=1;
               dfs[it]=1;
               if(iscyclehelper(it,adj,vis,dfs))return true;
           }
           else if(dfs[it])return true;
       }
       dfs[x]=0;
       return false;
       
   }
   
   
    bool isCyclic(int V, vector<int> adj[]) {
          vector <int> vis(V+1,0);
          vector <int> dfs(V+1,0);
          for(int i=0 ;i<V ;i++){
              if(!vis[i]){
                  if(iscyclehelper(i,adj,vis,dfs))return true;
              }
          }
        return false;  
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
