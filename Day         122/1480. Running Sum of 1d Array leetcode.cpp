class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n= nums.size();
        vector<int>prefix=nums;
        for(int i=1 ; i<n ; i++){
            prefix[i]+=prefix[i-1];
        }
        return prefix;
    }
};
