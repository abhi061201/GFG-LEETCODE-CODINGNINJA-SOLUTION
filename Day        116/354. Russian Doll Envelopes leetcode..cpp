class Solution {
public:
    static bool comp(vector<int>&v1, vector<int>&v2)
{
    return v1[0] == v2[0]? v1[1] > v2[1] : v2[0] > v1[0];
}

    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
            //         // Lis O(n^2 )Approach
            //         sort(env.begin(), env.end());
            //         vector<int>Lis(n,1);
            //         Lis[0]=1;
            //         for(int i=1 ; i<n ; i++){
            //             for(int j=0 ; j<i ; j++){

            //                 if(env[i][0]>env[j][0] && env[i][1]>env[j][1]){
            //                     Lis[i]= max(Lis[i],1+Lis[j]);
            //                 }

            //             }
            //         }
            //         int ans=0;
            //         for(auto it : Lis){
            //             ans= max(ans, it);
            //         }
            //         return ans;
        
        sort(env.begin(), env.end(),comp);
        vector<int>dp;
        int ans=1;
        dp.push_back(env[0][1]);
        for(int i=1 ; i<n ; i++){
            if(dp.back()<env[i][1]){
                dp.push_back(env[i][1]);
                ans++;
            }
            else {
             int x= lower_bound(dp.begin(), dp.end(), env[i][1])-dp.begin();
                dp[x]=env[i][1];
            }
        }
        return ans;
        
    }
};
