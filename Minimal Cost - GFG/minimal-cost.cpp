//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& h, int n, int k) {
        vector<int>dp(n,-1);
        return go(h,n-1,k,dp);
    }
    int go(vector<int>&h, int i, int k ,vector<int>&dp)
    {
        if(i<=0)return 0;
        if(dp[i]!=-1)return dp[i];
        int jump =1e9;
        for(int j=1; j<=k; j++)
        {
            if(i>=j)
            {
                jump = min(jump, abs(h[i]-h[i-j]) + go(h,i-j,k,dp));
            }
        }
        return dp[i]=jump;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends