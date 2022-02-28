TC= O(N)
SC= O(N)+O(N)

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




// Space optimised
TC= O(N)
SC= constant


#include<bits/stdc++.h>
int frogJump(int n, vector<int> &arr)
{
    int p2= 0;
    int p1= 0;
    for(int i=1 ;i<n ;i++){
        int left= p1+abs(arr[i]-arr[i-1]);
        int ss= INT_MAX;
        if(i>1){
            ss= p2+abs(arr[i]-arr[i-2]);
        }
        int val= min(left,ss);
//         cout<<val<<" , "<<p1<<" , "<<p2<<" , \n";
        p2=p1;
        p1=val;
      
        
    }
    return p1;
    
    
}
