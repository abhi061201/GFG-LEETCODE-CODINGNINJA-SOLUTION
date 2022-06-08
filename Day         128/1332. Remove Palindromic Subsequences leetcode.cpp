class Solution {
public:
    int removePalindromeSub(string s) {
        
        if(ispalindrome(s))return 1;
         return 2 ;
        
    }
    bool ispalindrome(string &s){
        int i=0,j= s.length()-1;
        
        while(i<=j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else return false;
        }
        return true;
    }
};
