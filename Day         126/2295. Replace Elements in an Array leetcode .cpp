class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        int n= nums.size();
        vector<int>temp(1000001,-1);
        
        for(int i=0 ; i<n ; i++){
            temp[nums[i]]=i;
        }
        for(auto it : op){
            temp[it[1]]=temp[it[0]];
            temp[it[0]]=-1;
        }
        vector<int>ans(n);
        for(int i=0 ; i<1000001 ; i++){
            if(temp[i]!=-1){
                ans[temp[i]]=i;
            }
            
        }
        return ans;
    }
};
