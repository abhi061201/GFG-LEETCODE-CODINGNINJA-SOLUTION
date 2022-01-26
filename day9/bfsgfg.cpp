 void bfs(int x ,vector<int> adj[] ,vector<int> &vis,vector<int> &v ){
        
        vis[x]=1;
        queue<int> q;
        q.push(x);
        while(!q.empty()){
            int temp= q.front();
            q.pop();
            v.push_back(temp);
            for(auto it : adj[temp]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector <int> v;
       
           
                bfs(0,adj,vis,v);
            
        
        return v;
    }
    
    
};
