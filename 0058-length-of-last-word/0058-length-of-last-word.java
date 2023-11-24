class Solution {
    public int lengthOfLastWord(String s) {
        int n= s.length();
        
        int j=n-1, ans=0;
        while(j>=0 && s.charAt(j)==' ')
        {
            j--;
        }
        while(j>=0 && s.charAt(j)!= ' ')
        {
            j--; 
            ans++;
        }
        return ans;
    }
}