void dfs_helper(int x,vector<vector<int>> &adj,vector<int>&vis,vector<int>&v){
	vis[x]=1;
	v.push_back(x);
	for(auto y : adj[x]){
		
			if(!vis[y]){
				dfs_helper(y,adj,vis,v);
			
		}
	}
	
	
}
vector<int> dfs(vector<vector<int>> &adj) {
    // add your logic here
	vector<int> v;
	
	int n= adj.size();
	vector<int> vis(n,0);
	dfs_helper(0,adj,vis,v);
	
		return v;
}
