// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    #define m 1000000007
	public:
		int nthPoint(int n){
		vector<long long int> dp(100000,-1);
		dp[1]=1;
		dp[2]=2;
		  return go(n,dp);
		    
		    
		}
		int go(int n, vector<long long int>&dp){
		    if(dp[n]!=-1){
		        return dp[n];
		    }
		    return dp[n]= (go(n-1,dp)%m+go(n-2,dp)%m)%m;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
