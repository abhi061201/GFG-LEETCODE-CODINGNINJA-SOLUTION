class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)continue;
                if(isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i, adj, vis);
                vis[i]=1;
                count++;
            }
        }
        return count;
    }
    void dfs(int i, vector<vector<int>>&adj, vector<int>&vis)
    {
        for(auto it: adj[i])
        {
            if(!vis[it])
            {
                vis[it]=1;
                dfs(it, adj, vis);
            }
        }
    }
};