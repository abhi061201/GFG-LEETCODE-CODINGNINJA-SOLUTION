// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mt) {
        // Code here
        int n= mt.size();
        int m= mt[0].size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        int ans= 1;
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<m ;j++){
                if(dp[i][j]==-1)
                ans= max(ans, dfs(i,j,m,n,mt, dp)) ;
            }
        }
        return ans;
    }
    int dfs(int i , int j , int m ,int n ,vector<vector<int>>& mt,vector<vector<int>>&dp){
        
        if(dp[i][j]!=-1)return dp[i][j];
      int path= 1;
      int dr[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
      for(int k=0 ;k<4 ;k++){
          int nbri= i+dr[k][0];
          int nbrj= j+dr[k][1];
          if(nbri>=0 && nbrj>=0 && nbri<n && nbrj<m  && mt[i][j]<mt[nbri][nbrj]){
              path= max(path , 1+ dfs(nbri, nbrj,m,n ,mt, dp));
          }
      }
      return dp[i][j]= path;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
