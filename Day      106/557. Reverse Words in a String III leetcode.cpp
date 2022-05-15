class Solution {
public:
    string reverseWords(string s) {
        string str,ans;
        
        for(int i=0 ; i<s.length() ; i++){
            
            if(s[i]==32){
                reverse(str.begin(), str.end());
                ans+=str;
                ans+=" ";
                str.erase();
            }
            else str.push_back(s[i]);
            
        
        }
        reverse(str.begin(), str.end());
        ans+=str;
        return ans;
    }
};
