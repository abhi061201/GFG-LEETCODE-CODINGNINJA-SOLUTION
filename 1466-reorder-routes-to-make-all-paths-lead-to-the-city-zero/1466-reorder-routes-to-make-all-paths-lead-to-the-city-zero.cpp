class Solution {
public:
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        set<pair<int,int>>se;
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            se.insert({it[0], it[1]});
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        int ans=0;
        vis[0]=1;
        while(!q.empty())
        {
            int curele= q.front();
            q.pop();
            for(auto it: adj[curele])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                    if(se.find({it,curele})==se.end()){
                        // cout<<curele<<" : "<<it<<endl;
                        ans++;
                    }
                }
            }   
        }
        return ans;
        
        
    }
};