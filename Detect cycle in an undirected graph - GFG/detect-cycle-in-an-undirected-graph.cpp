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
           if(!vis[i]){if(check(i,adj,vis))return 1;}
       }
       return 0;
    }
    bool check(int i, vector<int>adj[], vector<int>&vis)
    {
        queue<pair<int,int>>q;
        q.push({i,-1});
        vis[i]=1;
        while(!q.empty())
        {
            int cur = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto it: adj[cur])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,cur});
                }
                else if(par!= it)return 1;
            }
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