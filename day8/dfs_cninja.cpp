

void dfs(int x, vector<vector<int>> &graph, int vis[],vector<int>&temp){
     vis[x]=1;
     temp.push_back(x);
   for(auto it: graph[x]){
       if(!vis[it]){
           dfs(it,graph,vis,temp);
       }
   }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &graph)
{
   int vis[V]={0};
	vector<vector<int>> ans;
    for(int i=0 ;i<V ;i++){
        if(!vis[i]){
            vector<int>temp;
            dfs(i,graph,vis,temp);
            ans.push_back(temp);
            }
    }
    return ans;

}

 
     
 
