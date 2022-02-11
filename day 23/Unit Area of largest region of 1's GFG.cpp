// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n= grid.size();
        int m= grid[0].size();
        int ans= INT_MIN;
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<m ; j++){
                if(grid[i][j]==1){
                    int temp=1;
                      grid[i][j]=0;
                  dfs(i,j,grid,temp);
                    ans= max(temp,ans);
                }
            }
        }
        return ans;
        
    }
    
    void dfs(int x, int y,vector<vector<int>>& grid,int &temp){
       
        int n= grid.size();
        int m= grid[0].size();
        int dr[8][2]= {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        for(int k=0 ;k<8 ;k++){
            int dx= dr[k][0];
            int dy= dr[k][1];
            int nbrx= x+dx;
            int nbry= y+dy;
            if(nbrx<n && nbrx>=0 &&nbry<m && nbry>=0 && grid[nbrx][nbry]==1){
                grid[nbrx][nbry]=0;
                temp++;
               dfs(nbrx,nbry,grid,temp);
                  
                
            }
        }
     
        
        
    }
    
    
};

// { Driver Code Starts.
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
