// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        //code here
        stack<int> st;
        
        toposort(n,adj,st);
        vector<int> adjt[n];
        
        transpose(adjt,adj,n);
        int ans=0;
        component(adjt,st,ans,n);
        
        
        return ans;
        
    }
    void toposort(int n, vector<int>adj[],  stack<int> &st){
        
        vector<int>vis(n,0);
        for(int i=0 ;i<n ;i++){
            if(!vis[i])
            dfstopo(i,adj,st,vis);
        }
        
        
    }
     void dfstopo(int x, vector<int>adj[],  stack<int> &st, vector<int>&vis){
        vis[x]=1;
        for(auto it : adj[x]){
            if(!vis[it])
            dfstopo(it,adj,st,vis);
        }
        st.push(x);
    }
    void  transpose(vector<int>adjt[],vector<int>adj[],int n){
        
       for(int i=0 ;i<n ;i++){
           for(auto it : adj[i]){
               adjt[it].push_back(i);
           }
       }
    }
    void component(vector<int>adjt[],stack<int> &st,int &ans,int n){
        
        vector <int> vis(n,0);
     while(!st.empty()){
         int temp= st.top();
         st.pop();
         if(!vis[temp]){
             ans++;
             for(auto it : adjt[temp]){
                 if(!vis[it]){
                     dfsrev(it,adjt,vis);
                 }
             }
         }
     }
        
    }
    void dfsrev(int x,vector<int> adjt[], vector<int>& vis){
        vis[x]=1;
        for(auto it :adjt[x] ){
            if(!vis[it]){
                dfsrev(it,adjt,vis);
            }
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
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
