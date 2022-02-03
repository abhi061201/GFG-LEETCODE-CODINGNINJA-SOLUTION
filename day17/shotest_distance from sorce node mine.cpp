#include <bits\stdc++.h>
using namespace std;

void shortestPath(int src,vector<int>adj[],vector<int> &dist){

   queue<int> q;
   dist[src]=0;
   q.push(src);
   while(!q.empty()){
       int temp= q.front();
       q.pop();
       for(auto it : adj[temp]){
           if(dist[it] > dist[temp]+1){
               dist[it] = dist[temp]+1;
               q.push(it);
           }
       }
   }


}
int main(){
    
    cout<<" Enter the no. of nodes and no. of edges of the graph\n";
    int n,e;
    cin>>n>>e;
    cout<<"enter the edges\n";
    vector<int> adj[n];
    vector <int> dist(n,INT_MAX);
    
    for(int i=0 ;i<e ;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src;
    cout<<"Enter the source node\n";
    cin>>src;
    shortestPath(src,adj,dist);

   cout<<"Your Shortest distanec from the source node " <<src<< " will be : \n";
   for(int i=0 ;i<n ;i++){
       cout<<i<<" : "<<dist[i]<<"\n";
   }


    return 0;
}
