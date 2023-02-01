class Solution {
public:
    int n,m;
    
    string gcdOfStrings(string str1, string str2) {
        string s;
        n= str1.length() , m = str2.length();
        int i=0;
        while(i<n && i<m)
        {
            if(str1[i]==str2[i])s.push_back(str1[i++]);
            else break;
        }
        string temp=s;
        while(temp.size())
        {
            if(check(temp, str1, str2))return temp;
            temp.pop_back();
        }
        return "";
        
    }
    bool check(string &s, string &a, string &b)
    {
        int len= s.length();
        if(n%len|| m%len)return 0;
        int x= n/len, y= m/len;
        string temp1,temp2;
        
        while(x || y)
        {
            if(x)
            {
                temp1+=s;
                x--;
            }
            if(y)
            {
                temp2+=s;
                y--;
            }
        }
        return temp1==a && temp2==b;
    }
};