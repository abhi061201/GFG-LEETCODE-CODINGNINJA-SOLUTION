// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int sumi(int n, int arr[]){
        int sum=0;
        for(int i=0 ;i<n ;i++){
            sum+=arr[i];
        }
        return sum;
    }
    bool isSubsetSum(int n, int arr[], int sum){
       
       int s=sumi(n,arr);
       vector<vector<int>>dp(n+1,vector<int>(s+1,0));
       dp[0][0]=1;
       for(int i=1 ;i<=n ;i++){
           for(int j =0 ;j<=s ;j++){
               if(j>=arr[i-1]){
                   dp[i][j]= dp[i-1][j-arr[i-1]]|| dp[i-1][j];
               }
               else dp[i][j]= dp[i-1][j];
           }
       }
        if(dp[n][sum]==1)return true;
        else return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
