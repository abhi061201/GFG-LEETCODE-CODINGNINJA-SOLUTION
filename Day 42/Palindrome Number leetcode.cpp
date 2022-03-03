class Solution {
public:
    bool isPalindrome(int x) {
        string s= to_string(x);
        if(x<0)return 0;
        if(s.length()==1)return 1;
        int i=0;
        int j=s.length()-1;
        bool ans=true;;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else {ans=false;break;};
        }
        return ans;
    }
};
