class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        permutation(0,nums,ans);
        return ans;
    }
    
    void permutation(int start,vector<int>&nums, vector<vector<int>>&ans){
        if(start==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            swap(nums[i], nums[start]);
            permutation(start+1, nums, ans);
            swap(nums[i], nums[start]);
        }
        
        
    }
};
