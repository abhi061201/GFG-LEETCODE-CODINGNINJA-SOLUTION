class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n= s.length();
        //left to right
        
        int count=0;
        for(int i=0 ;i<n ;i++){
            if(s[i]=='('){
                count++;
            }
            if(s[i]==')'){
                
                if(count>0){
                    count--;
                }
                else s[i]='1';
                
            }
            
        }
        
        
        // right to left
        
        count=0;
        for(int i=n-1 ; i>=0 ;i--){
            
            if(s[i]==')'){
                count++;
            }
            if(s[i]=='('){
                
                if(count>0){
                    count--;
                }
                else s[i]='1';
                
            }
            
        }
        
        string ans="";
         // cout<<s<<" , ";
        // cout<<ans.length()<<" , ";
        for(int i=0 ;i<n ;i++){
            if(s[i]!='1')ans.push_back(s[i]);
        }
       
        if(ans.length()==0)return "";
        return ans;
    }
};
