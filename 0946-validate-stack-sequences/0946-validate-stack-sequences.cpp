class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        
        stack<int>st;
        int j=0;
        
        for(auto it : pu){
            st.push(it);
            
            while( !st.empty() && j<po.size() && po[j]==st.top()){
                st.pop();
                j++;
            }
        }
        if(j==po.size()){
            return true;
        }
        else return false;
        
    }
};