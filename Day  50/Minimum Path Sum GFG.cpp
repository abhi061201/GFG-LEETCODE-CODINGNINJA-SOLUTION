// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> mt)
    {
        // code here
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for(int i=0 ;i<n ;i++ ){
            dp[n-1][i]= mt[n-1][i];
        }
        
        for(int i=n-2 ;i>=0 ;i--){
            for(int j=0 ;j<n ;j++){
                
               if(i+1>=0 && j>=0 && i+1<n && j<n){
                   dp[i][j]= max(dp[i][j],dp[i+1][j]+mt[i][j]);
               }
               if(i+1>=0 && j+1>=0 && i+1<n && j+1<n){
                   dp[i][j]= max(dp[i][j],dp[i+1][j+1]+mt[i][j]);
               }
               if(i+1>=0 && j-1>=0 && i+1<n && j<n){
                   dp[i][j]= max(dp[i][j],dp[i+1][j-1]+mt[i][j]);
               }
            }
        }
        int ans=0;
        for(int i=0 ;i<n ;i++){
            ans= max(ans, dp[0][i]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
