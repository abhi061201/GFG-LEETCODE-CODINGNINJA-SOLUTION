class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        vector<vector<int>> ans;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>>se;
        vector<int>vis(n,0);
        for(int i= 0 ; i<n ;i++){
            int x= nums[i];
            int j=i+1, k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    se.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0)j++;
                else k--;
            }
        }
        for(auto it : se){
            ans.push_back(it);
        }
        return ans;
    }
};
