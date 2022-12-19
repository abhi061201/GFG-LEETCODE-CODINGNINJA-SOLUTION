class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>>adj(n);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
        }
        vector<int>vis(n,0);
        return go(s, d, adj,vis);
    }
    int go(int s, int d, vector<vector<int>>&adj,vector<int>&vis )
    {
        vis[s]=1;
        if(s==d)return 1;
        for(auto it: adj[s]){
            if(!vis[it]){
                if(go(it, d, adj, vis))return 1;
            }
        }
        return 0;
    }
};