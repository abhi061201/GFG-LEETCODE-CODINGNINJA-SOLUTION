#include <bits/stdc++.h>
void dfst(int x, vector<int> adjt[], vector<int> &vis, vector<int> &ans)
{
      vis[x] = 1; 
      ans.push_back(x);  
      for(auto it : adjt[x]){
            if(!vis[it]){
                dfst(it,adjt,vis,ans);
            }
      }
}
void go(vector<int> adjt[], stack<int> &st, vector<vector<int>> &ans, int n)
{
    vector<int> vis(n, 0);
    
    while(!st.empty()){
        int x = st.top();
        st.pop();
        if (!vis[x])
        {   vector<int> ansh;
            dfst(x, adjt, vis, ansh);
             ans.push_back(ansh);
        }
    } 
//     for(auto it : ansh){
//         cout<<it<<" , ";
//     }
   
   
}
void transpose(vector<int> adjt[], vector<int> adj[], int n)
{
    for (int i = 0; i < n; i++)
    {

        for (auto it : adj[i])
        {
            adjt[it].push_back(i);
        }
    }
}
void dfs(int i, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
            // st.push(it);
        }
        
    }
    st.push(i);
}
void toposort(int n, vector<int> adj[], stack<int> &st)
{
    vector<int> vis(n , 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
//     n++;
    vector<int> adj[n];
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
    }
    stack<int> st;
    toposort(n, adj, st);
    
    vector<int> adjt[n ];
    transpose(adjt, adj, n);
    vector<vector<int>>  ans;
    go(adjt, st, ans, n);
    return ans;
    
}
