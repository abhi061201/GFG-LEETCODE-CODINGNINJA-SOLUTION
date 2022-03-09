class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;
        
        go(st,s );
        
        if(st.size()==0)return true;
        
        return false;
    }
    void go(stack<char>&st , string s){
        
        int n= s. length();
        for(int i=0 ;i<n ;i++){
           if(st.empty())st.push(s[i]);
else if(s[i]==')' && st.top()=='(' || s[i]==']' && st.top()=='['||s[i]=='}' && st.top()=='{') {
            st.pop();
        }
            else st.push(s[i]);
           
        }
        
    }
};
