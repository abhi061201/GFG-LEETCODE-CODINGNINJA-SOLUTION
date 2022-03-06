// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define pp pair<int, pair<int,int>>
#define ff first
#define se second
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
         int n= grid.size();
         int m= grid[0].size();
         int cost=grid[0][0];
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]= grid[0][0];
        pq.push({grid[0][0],{0,0}});
         while(!pq.empty()){
             
             int dis= pq.top().ff;
             cost+=dis;
             int i= pq.top().se.ff;
             int j= pq.top().se.se;
             pq.pop();
             int dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
             for(int k=0 ;k<4 ;k++){
                 int nbrx=i+dr[k][0];
                 int nbrj=j+dr[k][1];
                 if(nbrx>=0 && nbrj>=0 && nbrx<n && nbrj<m ){
                     if(dist[nbrx][nbrj]>dis+grid[nbrx][nbrj]){
                         dist[nbrx][nbrj]=dis+grid[nbrx][nbrj];
                         pq.push({dist[nbrx][nbrj],{nbrx,nbrj}});
                     }
                 }
             }
             
         }
         
         
         
         
         
         return dist[n-1][m-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
