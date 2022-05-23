class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        
        int n= tri.size();
        vector<vector<int>>dp(n, vector<int>(n,1e9));
        for(int i=0 ; i<n ; i++){
            dp[n-1][i]= tri[n-1][i];
            
        }
        
        for(int i=n-2 ; i>=0 ; i--){
            
            for(int j=0; j<=i ; j++){
                dp[i][j]= tri[i][j]+ min(dp[i+1][j],dp[i+1][j+1]);
            }
        
        }
        return dp[0][0];
    }
}; 
