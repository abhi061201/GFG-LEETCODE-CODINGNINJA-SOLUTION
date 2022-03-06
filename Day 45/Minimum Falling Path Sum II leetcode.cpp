class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int i=0 ;i<n ;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        
        for(int i=n-2 ;i>=0 ;i--){
            for(int j=0 ;j<n ;j++){
                dp[i][j]= fun(i+1,j,n,dp)+matrix[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0 ;i<n ;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
    int fun(int i, int j,int n, vector<vector<int>>& matrix){
        
        int ans=INT_MAX;
        for(int k=-n ;k<n ;k++){
        
            if(j+k>=0 && j+k<n && k!=0){
                ans= min(ans,matrix[i][j+k]);
            }
        }
        return ans;
        
    }
};
