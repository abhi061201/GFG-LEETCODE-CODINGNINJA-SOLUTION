// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    
    
    
    
    vector<vector<int>> tarjans(int n, vector<int> adj[])
    {
        //code here
        vector<vector<int>> ans;
        stack<int> st;
        toposort(n,adj,st);
      
        vector<int> adjt[n];
      for(int i=0 ;i<n ;i++){
          for(auto it : adj[i]){
              adjt[it].push_back(i);
          }
      }
       
      dfsrev(st,adjt,ans,n);
       sort(ans.begin(),ans.end());
       return ans;
        
    }
    void toposort(int n,vector<int> adj[], stack<int>&st){
        
        vector<int>vis(n,0);
        for(int i=0 ;i<n ;i++){
            if(!vis[i]){
                dfs(i,adj,st,vis);
            }
        }
        
    }
    void dfs(int x,vector<int> adj[], stack<int>&st,vector<int>&vis){
        vis[x]=1;
        for(auto it : adj[x]){
            if(!vis[it]){
                dfs(it,adj,st,vis);
            }
        }
        st.push(x);
    }
    void dfsrev(stack<int> &st,vector<int>adjt[],vector<vector<int>>&ans,int n){
      vector<int>vis(n,0);
    while(!st.empty()){
          int temp= st.top();
      st.pop();
      if(!vis[temp]){
          vector<int>v;
          dfs_help(temp,adjt,v,vis);
          if(v.size())sort(v.begin(),v.end());
          ans.push_back(v);
         
      }
     }
        
    }
    void dfs_help(int x,vector<int>adjt[],vector<int>&v,vector<int>&vis){
        
        vis[x]=1;
        v.push_back(x);
        for(auto it : adjt[x]){
            if(!vis[it])dfs_help(it,adjt,v,vis);
        }
    }
    
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
