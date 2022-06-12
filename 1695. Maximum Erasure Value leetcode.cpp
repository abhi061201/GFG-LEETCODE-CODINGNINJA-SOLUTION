class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        vector<int>pref(n+1);
        pref[0]=nums[0];
        for(int i=1 ; i<n ; i++){
            pref[i]=nums[i]+pref[i-1];
        }
        vector<int>v(10001,-1);
        int i=0,j=0;
        for(j=0 ; j<n ; j++){
           
            if(v[nums[j]]!=-1){
                i= max(v[nums[j]]+1,i);
            }
            
            if(i==0)ans= max(ans,pref[j]);
            else ans= max(ans,pref[j]-pref[i-1]);
             v[nums[j]]=j;
        }
        return ans;
    }
};
