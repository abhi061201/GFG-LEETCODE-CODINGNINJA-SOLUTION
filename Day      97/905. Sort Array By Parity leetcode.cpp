class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
   
        vector<int >odd;
        vector<int> even;
        for(int i= nums.size()-1 ; i>=0 ; i--){
            if(nums[i]%2==0)even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        for(auto it : odd){
            even.push_back(it);
        }
        return even;
    }
};
