// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define ll long long int
#define N 1000000007
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        vector<ll> dp(n+1,-1);
        return fun(n,dp);
    }
    ll fun(ll n,vector<ll >&dp){
        if(n<=1 )return n;
        if(dp[n]!=-1)return dp[n];
        return( dp[n]= fun(n-1,dp)+fun(n-2,dp))%N;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
