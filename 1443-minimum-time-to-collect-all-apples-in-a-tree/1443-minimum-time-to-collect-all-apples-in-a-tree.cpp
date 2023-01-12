class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& app) 
    {
        vector<vector<int>>adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
      int ans=dfs(0,adj,app,-1);
        cout<<ans;
        return ans>0?ans-2:0;
    }
    int dfs(int i,vector<vector<int>>&adj, vector<bool>& app, int par )
    {
        int ans=0;
        for(auto it: adj[i])
        {
            if(it!=par)ans+= dfs(it,adj,app,i);
        }
        if(ans>0)return 2+ans;
        if(app[i])return 2;
        return 0;
    }
};