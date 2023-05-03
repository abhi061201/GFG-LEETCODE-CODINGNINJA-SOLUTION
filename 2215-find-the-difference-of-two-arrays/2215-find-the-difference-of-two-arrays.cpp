class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        ans.push_back(go(nums1, nums2));
        ans.push_back(go(nums2, nums1));
        return ans;
    }
    vector<int>go(vector<int>&a, vector<int>&b){
        
        set<int>sea(a.begin(), a.end());
        set<int>seb(b.begin(), b.end());
        vector<int>ans;
        for(auto it: sea)
        {
            if(seb.find(it)==seb.end())ans.push_back(it);
        }
        return ans;
    }
};