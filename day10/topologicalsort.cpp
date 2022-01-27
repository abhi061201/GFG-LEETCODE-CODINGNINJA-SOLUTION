#include <bits/stdc++.h>
using namespace std;


 void topologicalsort(int x,vector <int>adj[],vector<int> &vis,stack<int> &s){

    vis[x]=1;
    for(auto it : adj[x]){

        if(!vis[it]){
          
            topologicalsort(it,adj,vis,s);
        }
    }
    s.push(x);
 }
int main()
{
    int n, e;
    cout << "Enter the no. of nodes and no. of edges in your graph \n";
    cin >> n >> e;
    vector<int> adj[n];
    cout << "Enter the adjacency of your nodes\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    vector<int> vis(n,0);
    stack <int> s;
   

    for(int i=0 ;i<n ;i++){
        if(!vis[i]){
            topologicalsort(i,adj,vis,s);
        }
    }

    cout << "Your topological sort of graph is : \n";
   
    for(int i=0 ;i<n ;i++){
       cout<<s.top()<<" , ";
       s.pop();
    }
    

    return 0;
}
