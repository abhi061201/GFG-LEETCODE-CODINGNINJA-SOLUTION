class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n= edges.size();
        int ans=-1, curdist=1e9;
        vector<vector<int>>adj(n);
        for(int i=0; i<n;i++)
        {
            if(edges[i]!=-1)adj[i].push_back(edges[i]);
        }
        
        
        vector<int>vis1(n,0), vis2(n,0), dist1(n,0), dist2(n,0);
        
        dfs(node1, dist1, adj, vis1);
        
        
        dfs(node2, dist2, adj, vis2);
        
        for(int i=0;i <n;i++)
        {
            if(vis1[i] && vis2[i] && curdist > max(dist1[i], dist2[i]))
            {
                curdist= max(dist1[i], dist2[i]);
                ans =i;
            }
        }
        return ans;
        
        
    }
    
    void dfs(int i, vector<int>&v,vector<vector<int>>&adj, vector<int>&vis )
    {
        vis[i]=1;
         
        for(auto it:adj[i])
        {  
            if(!vis[it])
            {
                v[it]= 1+v[i];
                 vis[it]=1;
                dfs(it,v,adj,vis);
        }}
    }
    
    
        
        
        
        
        
        
        
        
        
        
        
};