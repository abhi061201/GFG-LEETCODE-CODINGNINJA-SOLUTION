class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int>se;
        se.push(-1);
        int n=s.length(), ans=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='(')se.push(i);
            else {
                 se.pop();
                if(se.empty()){
                   
                    se.push(i);
                }
                else {
                   
                    ans=max(ans, i-se.top());
                    
                }
            }
        }
        return ans;
        
    }
};
