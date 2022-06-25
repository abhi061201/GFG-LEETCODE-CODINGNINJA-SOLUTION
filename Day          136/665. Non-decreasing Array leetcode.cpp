class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n= nums.size(); 
        int maxi= nums[0];
        int cntmx= 0;
        for(int i=1 ; i<n ; i++){
            if(nums[i]< maxi){
                cntmx++;
            }
            else {
                maxi=nums[i];
            }
        }
        
        if(cntmx<=1)return 1;
        int cntmi= 0,mini=nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(mini < nums[i])cntmi++;
            else{
                mini=nums[i];
            }
        }
        if(cntmi<=1)return 1;
        
        return 0;
        
        
    }
};
