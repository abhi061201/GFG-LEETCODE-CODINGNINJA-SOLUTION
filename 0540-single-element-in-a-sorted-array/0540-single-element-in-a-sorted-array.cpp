class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0, h= nums.size()-1;
        int mid;
        while(h-l>1)
        {
            mid= (h+l)/2;
            
            int f_index= getFirstIndex(mid, nums);
            if(f_index==-1)return nums[mid];
            
            if(f_index%2==0)
            {
                l= mid;   
            }
            else 
            {
                h= mid;
            }
            
        }
        if(h%2==0)return nums[h];
        return nums[l];
    }
    int getFirstIndex(int x, vector<int>&nums)
    {
        if( x-1 >=0 && nums[x]== nums[x-1])return x-1;
        if(x+1 < nums.size() && nums[x] == nums[x+1])return x;
        return -1;
        
    }
};