class Solution {
public:
    int search(vector<int>& nums, int t) {
        
        int i= 0;
        int j= nums.size()-1;
        int ind=-1;
        while(i<=j ){
            if(nums[i]==t)ind=i;
            if(nums[j]==t)ind=j;
            
            i++;
            j--;
        }
        return ind;
    }
    
     
};
