class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>se;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        go(0, nums, temp);
        for(auto it: se)
            ans.push_back(it);
        return ans;
    }
    void go(int i, vector<int>&nums , vector<int>&temp)
    {
        if(i==nums.size())
        {
            if(temp.size()>=2)se.insert(temp);
            return ;
        }
        
        if(temp.size()==0)
        {
            temp.push_back(nums[i]);
            go(i+1, nums, temp);
            temp.pop_back();
            
        }
        else 
        {
            if(temp[temp.size()-1] <= nums[i])
            {
                temp.push_back(nums[i]);
                go(i+1, nums, temp);
                temp.pop_back();
            }
        }
        go(i+1, nums, temp);
        
    }
};