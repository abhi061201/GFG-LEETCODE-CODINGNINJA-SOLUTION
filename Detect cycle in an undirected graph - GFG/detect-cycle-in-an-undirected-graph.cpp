//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        vector<int>vis(n,0);
        for(int i=0; i<n; i++)
        {
            if(!vis[i]){vis[i]=1;if(checkcycle(i, adj, -1,vis))return 1;}
        }
        return 0;
    }
    bool checkcycle(int i, vector<int>adj[], int par, vector<int>&vis)
    {
        for(auto it: adj[i])
        {
            if(!vis[it]){
                vis[it]=1;
                if(checkcycle(it,adj,i,vis))return 1;
            }
            else if(par!= it)return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends