#define ll long long
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
        }
        long long ans=0;
        vector<int>vis(n,0), compo_count;
        
        for(int i=0; i<n;i++)
        {
            long long temp_count= 0;
            if(!vis[i]){
                dfs(i,adj,temp_count,vis);            
                ans+= temp_count* ((ll)n- temp_count);
            }
        }
        
        
        return ans/2;
    }
    void dfs(int i,vector<vector<int>>&adj, long long &temp_count,vector<int>&vis)
    {
        vis[i]=1;
        temp_count++;
        for(auto it: adj[i])
        {
            if(!vis[it])dfs(it, adj, temp_count, vis);
        }
    }
};