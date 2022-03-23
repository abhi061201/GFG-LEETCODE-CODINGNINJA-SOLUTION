TC= O(N)+ O(N*Target)+ O(N);
Sc= O(N*Target)


int sumd(vector<int>arr){
    int sum=0;
    for(auto it : arr)sum+=it;
    return sum;
}
int Solution::solve(vector<int> &arr) {

    int t= sumd(arr)/2;
    int n= arr.size();
    vector<vector<int>>dp(n+1, vector<int>(t+1, 0));
    for(int i=0 ; i<=n ;i++)dp[i][0]=1;\

    for(int i=1 ; i<=n ; i++){
        for(int tar= 1 ; tar<=t ; tar++){

            dp[i][tar]= dp[i-1][tar];
            if(tar>=arr[i-1]){
                dp[i][tar]= dp[i-1][tar] || dp[i-1][tar-arr[i-1]];
            }
        }
    }
    int ans=0;
    for(int i=t; t>=1; t-- ){
        if(dp[n][i]==1){
            ans=t;
            break;
        }
    }
    return sumd(arr)-2*t;
}
