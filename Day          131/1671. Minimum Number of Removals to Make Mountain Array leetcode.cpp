class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n= nums.size();
        vector<int>lisfor(n,1);
        vector<int>lisback(n,1);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i]> nums[j]){
                    lisfor[i]= max(lisfor[i], 1+lisfor[j]);
                }
            }
        }
        // for(auto it : lisfor)cout<<it<<" ";
        vector<int>rev;
        rev=nums;
        reverse(nums.begin(),nums.end());
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<i ; j++){
                if(nums[i]> nums[j]){
                    lisback[i]= max(lisback[i], 1+lisback[j]);
                }
            }
        }
        cout<<"\n";
        // for(auto it : lisback)cout<<it<<" ";
        reverse(lisback.begin(),lisback.end());
        int ans=0;
        for(int i=0 ; i<n ; i++){
            if(lisfor[i]>1 && lisback[i]>1)ans= max(ans,lisfor[i]+lisback[i]-1);
        }
        return n- ans;
    }
};
