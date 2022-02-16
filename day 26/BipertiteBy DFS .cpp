class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n= graph.size();
        vector<int>vis(n,0);
        vector<int>col(n,-1);
        vector<int>adj[n];
       for(int i=0 ;i<n ;i++)
       {
           for(auto it :graph[i]){
               
               adj[i].push_back(it);
               adj[it].push_back(i);
               
           }
       }
        for(int i=0 ;i<n ;i++){
            if(!vis[i]){
                if(!dfs(i,adj,col,vis,-1)){
                    return false;
                }
            }
        }
        
        
        
        
        return true;
    }
    bool dfs(int x, vector<int>adj[],vector<int>&col,vector<int>&vis,int par){
        vis[x]=1;
         if(par==-1)col[x]=0;
       else col[x]= 1-col[par];
       
        for(auto it: adj[x]){
            
            if(!vis[it]){
                if(!dfs(it,adj,col,vis,x))return false;
            }
             else if(vis[it]==1 &&col[it]==col[x])return false;
            
        }
        
        return true;
        
    }
    
};
