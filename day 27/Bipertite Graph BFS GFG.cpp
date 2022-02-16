// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int>col(n,-1);
	    
	    for(int i=0 ;i<n ;i++){
	        if(col[i]==-1){
	            if(!bipertite(i,adj,col,n)){
	                return false;
	            }
	        }
	    }
	    return true;
	    
	}
	bool bipertite(int i , vector<int>adj[], vector<int>&col ,int n){
	    queue<int > q;
	    col[i]=0;
	    q.push(i);
	    while(!q.empty()){
	        int temp= q.front();
	        q.pop();
	        for(int it : adj[temp]){
	            if(col[it]==-1){
	                col[it]=1-col[temp];
	                q.push(it);
	            }
	            else if(col[it]==col[temp])return false;
	        }
	    }
	    
	    return true;
	    
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
