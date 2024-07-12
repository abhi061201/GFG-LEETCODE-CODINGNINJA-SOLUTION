class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int>vec(n,-1);
        stack<int>st ;
        for(int i=0 ;i<n; i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'){
                vec[i]=st.top();
                vec[st.top()]=i;
                st.pop();
            }
        }
        string ans;
        for(int i=0, d=1; i<n; i+=d){
            if(vec[i]!=-1){
                d = -d;
                i= vec[i];
                
            }
            else {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};