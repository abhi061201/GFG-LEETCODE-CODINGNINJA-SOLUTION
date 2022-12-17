#define ll long long 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll>st;
        for(auto it: tokens)
        {
            if(it=="+" ||it=="-" ||it=="*" ||it=="/" )
            {
                ll x= st.top();
                st.pop();
                ll y= st.top();
                st.pop();
                x= perform(y, x, it);
                // cout<<x<<endl;
                st.push(x);
            }
            else {
                st.push(stol(it));
            }
        }
        return st.top();
    }
    ll perform(ll x, ll y, string s)
    {
        if(s=="+" ){
            return x+y;
        }
         if(s=="-" ){
            return x - y;
        }
         if(s=="*" ){
            return x * y;
        }
         if(s=="/" ){
            return x / y;
        }
        return 0;
    
    
    }
};