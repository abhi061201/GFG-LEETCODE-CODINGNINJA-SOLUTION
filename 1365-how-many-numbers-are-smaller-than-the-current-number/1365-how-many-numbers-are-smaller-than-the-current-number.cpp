class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>copy= nums;
        sort(copy.begin() , copy.end());
        vector<int>ans;
        for(auto it: nums)
        {
            int in= lower_bound(copy.begin(), copy.end(),it)-copy.begin();
            ans.push_back(in);
        }
        return ans;
    }
};