//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
   int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
        // vector<<vector<int>>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        int step=0;
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<m ;j++){
               if(grid[i][j]==2){
                   q.push({i,j});
                 }
               }
        }
      int  dr[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
          while(!q.empty()){
              
              int size= q.size();
              for(int i=0 ; i<size;i++){
                  int x= q.front().first;
                  int y= q.front().second;
                  
                 q.pop();
                 for(int k=0 ;k<4 ;k++){
                    int dx= dr[k][0];
                    int dy= dr[k][1];
                     
                int nbrx = x+dx;
                int nbry = y+dy;
                 
            if(nbrx>=0 && nbrx<n && nbry>=0 && nbry <m && grid[nbrx][nbry]==1 ){
                      grid[nbrx][nbry]=2;
                      q.push({nbrx,nbry});
                     
                    }
            }
                  
                  
        }
            if(!q.empty())step++;
          }  
          
          for(int i=0 ;i<n; i++){
            for(int j=0 ;j<m ;j++){
               if(grid[i][j]==1){
                   step=-1;
                   break;
                 }
               }
        }
        
        
            return step;
            
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends