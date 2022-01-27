class Solution {
public:
   
    bool  iscycle(int x, vector<int>adj[], vector<int> &vis ,vector<int>&dfs){
        
        vis[x]=1;
        dfs[x]=1;
        for(auto it : adj[x]){
            if(!vis[it]){
                vis[it]=1;
                dfs[it]=1;
                if(iscycle(it,adj,vis,dfs))return true;
            }
            else if(dfs[it]==1){return true;}
        }
        dfs[x]=0;
        return false;
        
    }
    
    bool canFinish(int V, vector<vector<int>>& pre) {
        vector <int> vis(V+1,0);
        vector <int> dfs(V+1,0);
        vector <int> adj[V+1];
        for(auto it : pre){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0 ;i<V ;i++){
            if(!vis[i]){
                if(iscycle(i,adj,vis,dfs))return false;
            }
        }
        return true;
        
    }
};
