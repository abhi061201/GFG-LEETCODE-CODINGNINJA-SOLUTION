class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
       stack<char> st1,st2;
       for(auto it : s){
           if(it=='#' && st1.size()>0)st1.pop();
           else if(it!='#') st1.push(it);
       }
        
         for(auto it : t){
           if(it=='#' && st2.size()>0)st2.pop();
           else if(it!='#') st2.push(it);
       }
        // while(!st1.empty()){cout<<st1.top();st1.pop();}
        // cout<<"\n";
        // while(!st2.empty()){cout<<st2.top();st2.pop();}
        if(st1.size()!=st2.size())return 0;
        
        
        while(!st1.empty()){
            if(st1.top()!=st2.top())return 0;
            st1.pop();
            st2.pop();
        }
        
        
        
        return 1;
    }
};
