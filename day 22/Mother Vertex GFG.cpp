// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int n, vector<int>adj[])
	{
	  int ans=INT_MAX;
	    for(int i=0 ;i<n ;i++){
	    vector<int> v;
	    vector<int> vis(n,0);
	    dfs(i,adj,v,vis);
	   // for(auto it : v)cout<<it<<" , ";
	   // cout<<"\n";
	   
            if(v.size()==n)ans= min(ans,i);
            // if(v.size()==0)ans=-1;
    }
    if(ans==INT_MAX)return -1;
    return ans;
	   
	}
		void dfs(int x, vector<int>adj[],vector<int>&v,vector<int>&vis){
	    vis[x]=1;
	    v.push_back(x);
	    for(auto it : adj[x]){
	        if(!vis[it]){
	            dfs(it,adj,v,vis);
	        }
	    }
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
