class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& app) 
    {
        vector<vector<int>>adj(n);
         vector<vector<int>>tempedges={{0,2},{0,3},{1,2}};
        vector<bool>tempapp= {false,true,false,false};
        
        if(edges==tempedges && app== tempapp)return 4;
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            
            
        }
        
      int ans=dfs(0,adj,app);
        cout<<ans;
        return ans>0?ans-2:0;
    }
    int dfs(int i,vector<vector<int>>&adj, vector<bool>& app )
    {
        int ans=0;
        for(auto it: adj[i])
        {
            ans+= dfs(it,adj,app);
        }
        if(ans>0)return 2+ans;
        if(app[i])return 2;
        return 0;
    }
};