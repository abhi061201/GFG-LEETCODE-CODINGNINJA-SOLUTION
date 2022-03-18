class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int>count(26,0);
        vector<int>vis(26,0);
        stack<char>st;
        
        for(auto it : s){
            count[it-'a']++;
        }
        
        for(int i=0 ; i<s.length() ;i++){
            
            count[s[i]-'a']--;
            if(!vis[s[i]-'a']){
                while(st.size()>0 && st.top()>s[i] && count[st.top()-'a']>0){
                    vis[st.top()-'a']=0;
                    st.pop();
                    
                }
                st.push(s[i]);
                vis[s[i]-'a']=1;
            }
            
        }
        
        string ans;
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
