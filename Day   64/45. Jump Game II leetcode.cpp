class Solution {
public:
    int jump(vector<int>& nums) {
        
        int reach=0;
        int cur=0,n=nums.size();
        int ans=0;
        for(int i=0 ; i<n-1 ; i++){
            reach = max(reach, i+nums[i]);
            
            if(i==cur){
                ans++;
                cur=reach;
            }
            
        }
        return ans;
        
    }
};
