class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n= nums.length;
        int ans[]= new int[2];
        for(int i=0; i<n; i++)
        {
            int x= target-nums[i];
            for(int j=i+1; j<n; j++)
            {
                if(x==nums[j]){
                    ans[0]=i;
                    ans[1]=j;
                    break;
                }
            }
            
        }
        return ans;
    }
}