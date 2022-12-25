class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        vector<int>ans;
        for(int i=1; i<n; i++)
        {
            nums[i]+= nums[i-1];
        }
        
        for(auto it: queries)
        {
            int in= upper_bound(nums.begin(), nums.end(),it)-nums.begin();
            ans.push_back(in);
        }
        return ans;
    }
};