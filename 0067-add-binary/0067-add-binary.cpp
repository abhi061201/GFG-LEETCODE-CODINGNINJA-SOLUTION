class Solution {
public:
    string addBinary(string a, string b) {
        int n= a.length(), m= b.length(), i=0, carry=0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string ans;
        while(i<max(n,m))
        {
            
            int lx= getval(a,i), ly= getval(b,i);
            
            int temp= (lx+ly+carry);
            ans.push_back((temp)%2+'0');
            carry= temp/2;
            
            i++;
        }
        if(carry)ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans.size()?ans:"0";
        
    }
    int getval(string &str, int i)
    {
        if(i>=str.length())return 0;
        return int(str[i]-'0');
    }
    
};