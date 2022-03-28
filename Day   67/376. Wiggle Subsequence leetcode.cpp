class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n= nums.size();
        int up=1, dow=1;
        for(int i=1 ; i<n ; i++){
            int diff= nums[i]-nums[i-1];
            if(diff>0)up= dow+1;
            if(diff<0)dow= up+1;
        }
        
        return max(up,dow);
        
    }
};
