class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
       string ans;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]!=')')st.push(s[i]);
            else {
                string temp;
                while(!st.empty() && st.top()!='('){
                    temp.push_back( st.top());
                    st.pop();
                }
                st.pop();
                for(int j=0; j<temp.length(); j++){
                    st.push(temp[j]);
                }
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};