class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int>vis(26, 0);
        stack<char>st;
        
        vector<int>count(26,0);
        
        for(auto it : s){
            count[it-97]++;
        }
       for(int i=0 ; i<s.length() ; i++){
           
           int  ch= s[i]-'a';
           count[ch]--;
           if(!vis[ch]){
              vis[ch]=1; 
               while(st.size()>0 && st.top()>s[i] && count[st.top()-'a']>0  ){
                   
                   vis[st.top()-'a']=0;
                   st.pop();
               }
               st.push(s[i]);
           }
       }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        
       reverse(ans.begin(), ans.end());
        return ans ;
        
        
    }
};
