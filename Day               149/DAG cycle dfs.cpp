TC= O(N+E)
SC = O(N+ N+N+N)   // rec + vis+ dfs+ adj

#include <bits/stdc++.h>
using namespace std;

bool iscycle(int i,vector<int>&dfs,vector<int>&vis, vector<vector<int>>&adj)
{
    vis[i]=1;
    dfs[i]=1;
    for(auto it: adj[i])
    {
        if(!vis[it])
        {
            if(iscycle(it, dfs, vis,adj))return 1;
        }
        else if(dfs[it]==1)return 1;
    }
    dfs[i]=0;
    return 0;
}

bool cycleDAGdfs(int n, vector<vector<int>>&edges)
{

    vector<int>dfs(n,0);
    vector<int>vis(n,0);
    vector<vector<int>>adj(n);
    for(auto it: edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i] && iscycle(i, dfs, vis , adj))return 1;

    }
    return 0;
}

int main()
{

    cout<<"enter the no. of edges and vertex of graph\n";
    int n,v;
    cin>>n>>v;
    vector<vector<int>>edges(n);
    cout<<"enter the edges\n";
    for(int i=0;i<n;i++)
    {
        int x, y;
        cin>>x>>y;
        edges[i]={x,y};
    }

    bool ans= cycleDAGdfs( v, edges);
    if(ans)cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
