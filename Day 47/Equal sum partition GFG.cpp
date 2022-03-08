// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int sumarray(int n , int arr[]){
        
        int ans=0;
        for(int i=0 ;i<n ;i++){
           
           ans+=arr[i];
            
        }
        return ans;
    } 
    int equalPartition(int n, int arr[])
    {
        int sum= sumarray(n,arr);
        if((sum%2)==  1 )return false;
        
        vector<vector<int>>dp(n+1, vector<int>((sum/2) +1 ,-1));
        return go(n-1, sum/2, arr,dp);
        
    }
    
    int go(int i , int sum , int arr[], vector<vector<int>>&dp){
        
        // if(i<0)return false;
        
        if(i<=0){
            
            if(sum==0)return 1;
            else return false;
            
        }
        
        if(dp[i][sum]!=-1)return dp[i][sum];
        
        int take = 0;
        int non_take = 0;
        
        non_take = go(i-1, sum, arr,dp);
        if(sum>=arr[i])take = go(i-1 , sum-arr[i], arr,dp);
        
        return dp[i][sum] =  non_take || take;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
