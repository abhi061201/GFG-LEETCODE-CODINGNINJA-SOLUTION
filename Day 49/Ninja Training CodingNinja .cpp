#include<bits/stdc++.h> 
int go(int i , int prev,  vector<vector<int>> &points, vector<vector<int>>&dp){
    
//     if(i==-1)return 0;
     if(i==0){
         int maxi=0;
         for(int j=0 ; j<3 ;j++ ){
             if(j!=prev){
                 maxi= max(maxi, points[0][j]);
             }
         }
         return maxi;
     }
    if(dp[i][prev]!=-1)return dp[i][prev];
    
    int maxi=0;
    for(int j=0 ;j<3 ;j++){
        
        if(j!=prev)maxi= max(maxi, points[i][j]+ go(i-1, j, points,dp));
    }
    return dp[i][prev] =maxi;
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n+1, vector<int>(4,-1));
    return go(n-1, 3, points,dp);
    
}

