class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n= v.size();
        
        vector<int>lis(n+1,1);
        for(int i=1 ;i<n ;i++){
            for(int j=0 ;j<i ;j++){
                if(v[i]>v[j]){
                    lis[i]= max(lis[i],1+lis[j]);
                }
            }
        }
        int ans=0;
        for(auto it :lis){
            ans= max(ans,it);
        }
        return ans;
        
    }
};
