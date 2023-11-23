class Solution {
    public int[] twoSum(int[] nums, int target) {
        int ans[]= new int[2];
        
        int n= nums.length;
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer> ();
        
        for(int i= 0; i<n; i++){
            if(mp.containsKey(target-nums[i])){
                ans[0]=i;
                ans[1]= mp.get(target-nums[i]);
                break;
            }
            else{
                mp.put(nums[i], i);
            }
        }
        return ans;
        
    }
}