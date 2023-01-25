class Solution {
public:
    set<vector<int>>se;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        go(0, nums, temp);
        vector<vector<int>>ans(se.begin() , se.end());
        
        return ans;
    }
    void go(int i, vector<int>&nums, vector<int>temp)
    {
        if(i==nums.size())
        {
            sort(temp.begin(), temp.end());
            se.insert(temp);
            return;
        }
        go(i+1, nums, temp);
        temp.push_back(nums[i]);
        go(i+1, nums, temp);
       
        temp.pop_back();
    }
};