#include <bits/stdc++.h>
using namespace std;
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
void go(vector<int> adjt[], stack<int> &st, vector<int>&ans, int n)
{
    vector<int> vis(n, 0);
    while(!st.empty()){
        int x = st.top();
        st.pop();
        if (!vis[x])
        {
            dfst(x, adjt, vis, ans);
        }
    }
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
    for (int i = 1; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
}
int main()
{
    cout << "Enter the no. of vertex and no. of Edges of a directed Graph\n";
    int n, e;
    cin >> n >> e;
    cout << "Enter the Edges\n";
    n++;
    vector<int> adj[n ];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    toposort(n, adj, st);
    
    vector<int> adjt[n + 1];
    transpose(adjt, adj, n);

    vector<int> ans;
    go(adjt, st, ans, n);
    for(auto it : ans){
        cout<<it<<" , ";

    }
    // while(!st.empty()){
    //     cout<<st.top()<<" ,";
    //     st.pop();
    // }
    cout<<"\n";

    return 0;
}
