#include<bits/stdc++.h>
int go(int i,vector<int>&arr,vector<int>&dp){
    if(i==0)return 0;
    if(dp[i]!=-1)return dp[i];
   int right= INT_MAX;
    int left= go(i-1,arr,dp)+abs(arr[i]-arr[i-1]);
    if(i>1)
      right= go(i-2,arr,dp)+abs(arr[i]-arr[i-2]);
       
    return dp[i]= min(left,right);
    
}
int frogJump(int n, vector<int> &arr)
{
    vector<int>dp(n,-1);
   return go(n-1,arr,dp);
}
