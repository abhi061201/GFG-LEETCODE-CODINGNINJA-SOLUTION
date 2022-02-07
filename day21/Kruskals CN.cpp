#include <bits/stdc++.h>
int par(int x,vector<int>&rank,vector<int>&parent){
    if(parent[x]==x)return x;
   return parent[x]=par(parent[x],rank,parent);
    
}
void unite(int x,int y,vector<int>&rank,vector<int>&parent){
    if(rank[x]>rank[y]){
        parent[y]=x;
    }
     else if(rank[x]<rank[y]){
        parent[x]=y;
    }
    else {
        parent[y]=x;
        rank[x]++;
    }
    
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    int cost=0;
    vector<int> parent(n+1,0);
    for(int i=0 ;i<=n ;i++){
        parent[i]=i;
    }
    vector<int>rank(n+1,0);
    
    vector<pair<int,pair<int,int>>> v;
    for(auto it : graph){
        int x= it[0];
        int y= it[1];
        int w= it[2];
        v.push_back({w,{x,y}});
        
    }
    sort(v.begin(),v.end());
    for(auto it : v){
       int w= it.first;
        int b= it.second.first;
        int c= it.second.second;
        int x= par(b,rank,parent);
        int y= par(c, rank,parent);
       
        if(x!=y){
            unite(x,y,rank,parent);
            cost+=w;
        }
    }
    return cost;
}
