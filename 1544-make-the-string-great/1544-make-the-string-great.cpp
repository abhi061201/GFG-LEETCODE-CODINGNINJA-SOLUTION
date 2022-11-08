class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto it: s)
        {
            if(st.empty()){
                st.push(it);
                continue;
            }
            
            if(st.top()== it-'a' +'A' || st.top() == it+'a' -'A')st.pop();
            else st.push(it);
            
        }
        string temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
            
        }
        reverse(temp.begin(), temp.end());
        return temp; 
    }
};