class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<int>st;
        
        // when closing bracket count is greater than open bracket
        st.push(-1);   
        for(int i=0; i<s.length() ; i++)
        {
            if(s[i]=='(')st.push(i);
            
            else 
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                
                else 
                {
                    ans= max(ans, i-st.top());
                }
                
            }
        }
        return ans;
    }
};