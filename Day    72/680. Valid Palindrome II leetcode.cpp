class Solution {
public:
    bool validPalindrome(string s) {
        
        int n= s.length();
        int j=n-1;
        for(int i=0 ; i<n/2 ; i++){
            if(s[i]==s[j]){
                j--;
                continue ;}
            else return ispalindrome(s,i,j-1)|| ispalindrome(s,i+1,j);
        }
        return true;
    }
    
    bool ispalindrome(string s, int i, int j){
        while(i<j){
            
            if(s[i]==s[j]){
                i++;j--;
            }
            else return false;
            
        }
        return true;
    }
};
