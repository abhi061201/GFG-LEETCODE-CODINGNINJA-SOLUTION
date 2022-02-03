// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& p) {
         vector<int> adj[N];
         vector <int> vis(N+1,0);
          vector <int> dfs(N+1,0);
         for(auto it : p){
             adj[it.second].push_back(it.first);
         }
        for(int i=0 ;i<N ;i++){
            if(!vis[i]){
                if(isCycle(i,adj,vis,dfs))return false;
            }
        }
        return true;
	}
	bool isCycle(int x, vector<int> adj[] ,vector <int> &vis, vector<int> & dfs){
	    vis[x]=1;
	    dfs[x]=1;
	    for(auto it : adj[x]){
	        if(!vis[it]){
	            vis[it]=1;
	            dfs[it]=1;
	            if(isCycle(it,adj,vis,dfs))return true;
	        }
	        else if(dfs[it]==1)return true;
	    }
	    dfs[x]=0;
	  return false;  
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
