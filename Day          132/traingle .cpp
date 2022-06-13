class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n= tri.size();
        
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int i=0 ; i<n ; i++){
            dp[n-1][i]=tri[n-1][i];
            
        }
        for(int i=n-2 ; i>=0 ; i--){
            for(int j=0; j<=i; j++){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+ tri[i][j];
            }
        }
        return dp[0][0];
    }
};



memoisation

class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n= tri.size();
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
       return go(0,0,n,tri,dp);
     
    }
    int go(int i,int j,int n,vector<vector<int>>& tri,vector<vector<int>>&dp){
        if(i==n-1)return tri[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]= tri[i][j]+ min(go(i+1,j,n,tri,dp),go(i+1,j+1,n,tri,dp));
    }
    
};
