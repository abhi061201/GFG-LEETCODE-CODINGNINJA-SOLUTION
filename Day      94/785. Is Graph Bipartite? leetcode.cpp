class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
      
        vector<int>vis(n,0);
        vector<int>col(n,-1);
        int x=1;
    for(int i=0 ; i<n ; i++){
        if(!vis[i]){
             x=bfs(i,vis,col,graph);
            if(!x)return false;
        }
    }    
    
       return x; 
        
 }
    int bfs(int i, vector<int>&vis, vector<int>&col, vector<vector<int>>& graph){
        queue<pair<int,int>>q;
        q.push({i,0});
        col[i]=0;
        while(!q.empty()){
            
            int cur_node= q.front().first;
            int cur_col=  q.front().second;
            q.pop();
            
            vis[cur_node]=1;
            for(auto it : graph[cur_node]){
               if(vis[it]){
                   if(col[it]==col[cur_node]){
                        if(it!=cur_node)return false;  
                   }
               }
                else {
                    cout<<"h"<<"\n";
                    if(col[it]==col[cur_node])return false;
                    if(col[it]==-1){
                        col[it]= 1-col[cur_node];
                        q.push({it,col[it]});
                    }
                    
                }
                
               
                
            }
            
        }
        return true;
    }
};
