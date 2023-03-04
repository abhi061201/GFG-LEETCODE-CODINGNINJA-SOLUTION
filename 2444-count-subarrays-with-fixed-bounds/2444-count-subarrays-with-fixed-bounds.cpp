#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n= nums.size();
        ll count=0;
        int start=0, latest_mink=-1, latest_maxk=-1;
        for(int i=0; i<n; i++)
        {
            if(nums[i] > maxK || nums[i]< minK)
            {
                start= i+1;
                latest_mink=i;
                latest_maxk=i;
                continue;
            }
            if(nums[i]==minK)latest_mink= i;
            if(nums[i]==maxK)latest_maxk= i;
            int total_subarray_from_start_to_i= i-start+1;
            
            int discard_subarray= i-(min(latest_mink, latest_maxk)+1)+1;
            count+= total_subarray_from_start_to_i- discard_subarray;
        }
        return count;
    }
};