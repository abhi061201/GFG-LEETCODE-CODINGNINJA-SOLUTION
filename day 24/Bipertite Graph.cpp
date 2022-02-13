// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> col(V,-1);
	    for(int i=0 ;i<V ;i++ ){
	        if(col[i]==-1){
	           if( !checkBipartite(i,V,adj,col)){
	               return false;
	           }
	        }
	    }
	    return true;
	}
	bool checkBipartite(int src,int n, vector<int>adj[],  vector<int>&col){
	   
  queue <int> q;
  q.push(src);
  col[src]=0;
  while(!q.empty()){
      int temp= q.front();
      q.pop();
      //int newcol= 1;
      //if(col[temp]==1)newcol=0;
      for(auto it : adj[temp]){
          if(col[it]==-1){
              col[it]=1-col[temp];
              q.push(it);
          }
          else if(col[it]==col[temp]){
              return false;
          }

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
