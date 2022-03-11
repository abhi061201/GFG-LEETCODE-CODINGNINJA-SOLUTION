class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        
        int n= ob.size();
        int m= ob[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return go(n-1,m-1,ob,dp );
        
        
        
    }
    int go(int i , int j, vector<vector<int>>& ob , vector<vector<int>>&dp ){
        
        if(i==0 && j==0 && ob[i][j]!=1)return 1;
        if(i<0 || j<0 )return 0;
        int left=0;
        int up=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(ob[i][j]==1)return 0;
        if(ob[i][j]!=1){
            left= go(i-1, j,ob,dp);
            up= go(i, j-1, ob,dp);
        }
        
        return dp[i][j]= left+up;
    }
    
};
