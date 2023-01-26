class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     vector<int>dist(n,1e9);
        
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        dist[src] = 0;
        int steps=0;
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty() && steps<=k)
        {
            int n= q.size();
            while(n--)
            {
                int curnode= q.front().first;
                int cost= q.front().second;
                q.pop();
                for(auto it: adj[curnode])
                {
                    if(dist[it.first] > cost+ it.second)
                    {
                        dist[it.first] = cost+ it.second;
                        q.push({it.first, dist[it.first]});
                    }
                }
                
            }
            steps++;
        }
        
        for(auto it: dist)cout<<it<<" , ";
        return dist[dst]==1e9? -1: dist[dst];
    }
};