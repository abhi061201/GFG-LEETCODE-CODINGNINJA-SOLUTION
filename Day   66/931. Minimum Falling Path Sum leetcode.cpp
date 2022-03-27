class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0 ) );
        for(int i=0 ; i<n ; i++){
            dp[n-1][i]= matrix[n-1][i];
        }
        
        
        for(int i=n-2; i>=0 ; i--){
            for(int j=0 ; j<n ; j++){
                int mini=INT_MAX;
                if(j-1>=0){
                    mini= min(mini,dp[i+1][j-1]);
                    
                }
                if(j+1<n){
                    mini= min(mini,dp[i+1][j+1]);
                  
                }
                mini= min(mini,dp[i+1][j]);
                
                dp[i][j]= matrix[i][j]+mini;
            }
        }
        int ans=INT_MAX;;
        for(int i=0 ; i<n ; i++){
            ans= min(ans, dp[0][i]);
        }
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ;j<n ; j++){
                cout<<dp[i][j]<<" , ";
                
            }
            cout<<"\n";
        }
        return ans;
    }
};
