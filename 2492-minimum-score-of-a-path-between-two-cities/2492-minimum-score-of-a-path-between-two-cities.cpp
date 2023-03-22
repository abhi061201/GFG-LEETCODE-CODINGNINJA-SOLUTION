class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        queue<pair<int,int>>q;
        q.push({1,1e9});
        vector<int>vis(n+1,0);
        int ans = 1e9;
        vis[0]=1;
        vis[1]=1;
        while(!q.empty())
        {
            int node= q.front().first;
            int curdis= q.front().second;
            q.pop();
            ans= min(ans, curdis);
            vis[node]=1;
            for(auto it: adj[node])
            {
                if(!vis[it.first])
                {
                    
                    // cout<<node<<" : "<<it.first<<" : "<<it.second<<endl;
                    q.push({it.first, it.second});
                
                }
            }
            
        }
        return ans;
        
    }
};