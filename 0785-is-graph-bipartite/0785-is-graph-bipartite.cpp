class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>vis(n,0);
        for(int i=0; i<n;i++)
        {
            if(!vis[i])if(!isbipertite(i,graph, vis))return 0;
            
        }
        return 1;
    }
    bool isbipertite(int i, vector<vector<int>>& adj,vector<int>& vis)
    {
        
        queue<int>q;
        int n= adj.size();
        vector<int>color(n,-1);
        q.push(i);
        vis[i]=1;
        color[i]=0;
        while(!q.empty())
        {
            int curnode= q.front();
            
            q.pop();
            for(auto it: adj[curnode])
            {
                if(!vis[it])
                {
                   q.push(it);
                    vis[it]=1;
                    color[it]= 1- color[curnode];
                }
                else if(color[it]== color[curnode])return false;
            }
        }
        return 1;
    }
};