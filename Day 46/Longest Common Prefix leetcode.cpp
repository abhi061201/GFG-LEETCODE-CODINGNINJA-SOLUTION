class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        
        int n= str.size();
        if(n==1)return str[0];
        string s=go(str[0], str[1]);
        for(int i=2 ; i<n ;i++){
            s= go(s,str[i]);
        }
        return s;
    }
    
    string go(string s1, string s2){
        int i=0 ;
        int x= min(s1.length(), s2.length());
        string s="";
        while(i<x && s1[i]==s2[i]){
            s.push_back(s1[i]);
           i++;
        }
        return s;
    }
    
};
