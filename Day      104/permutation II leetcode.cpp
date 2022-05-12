class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>>ans;
        set<vector<int>>se;
        permutation(0,nums,se);
        
        for(auto it : se){
            ans.push_back(it);
            
        }
        return ans;
    }
    
    void permutation(int start,vector<int>&nums ,set<vector<int>>&se ){
        
        if(start==nums.size()){
            se.insert(nums);
            return ;
        }
        
        for(int i=start; i<nums.size(); i++){
            swap(nums[i], nums[start]);
            permutation(start+1, nums, se);
            swap(nums[i], nums[start]);
        }
    }
};
