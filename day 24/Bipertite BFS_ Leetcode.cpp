class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> col(n,-1);
        for(int i=0 ;i<n; i++){
            for(auto it : graph[i]){
                if(!checkBipertite(it,graph,col)){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkBipertite(int src,vector<vector<int>>& graph,vector<int>col){
        
        queue<int> q;
        q.push(src);
        col[src]=0;
        while(!q.empty()){
            int temp= q.front();
            q.pop();
            for(auto it : graph[temp]){
                if(col[it]==-1){
                    col[it]= 1-col[temp];
                    q.push(it);
                    
                }
                else if(col[it]==col[temp]){
                    return false;
                }
            }
        }
        
        
        
        
        return true;
    }
};
