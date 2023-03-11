class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        int n= p.length();
        if(n<8)return 0;
        int lowercase= 0, upper=0, digit=0,spl=0;
        for(int i=0;i<n-1;i++)
        {
            if(p[i]==p[i+1])return 0;
            if(p[i]-'a'>=0 && p[i]-'a'<26)lowercase=1;
            else if(p[i]-'A'>=0 && p[i]-'A'<26)upper=1;
            else if(p[i]=='!' ||p[i]=='@' ||p[i]=='#' ||p[i]=='$' ||p[i]=='%' ||p[i]=='^' ||p[i]=='&' ||p[i]=='*' ||p[i]=='(' ||p[i]==')' ||p[i]=='-' ||p[i]=='+')spl=1;
            else if(p[i]=='0' ||p[i]=='1' ||p[i]=='2' ||p[i]=='3' ||p[i]=='4' ||p[i]=='5' ||p[i]=='6' ||p[i]=='7' ||p[i]=='8' ||p[i]=='9'  )digit=1;
        }
        int i=n-1;
        if(p[n-1]-'a'>=0 && p[n-1]-'a'<26)lowercase=1;
        else if(p[n-1]-'A'>=0 && p[n-1]-'A'<26)upper=1;
        
        else if(p[i]=='!' ||p[i]=='@' ||p[i]=='#' ||p[i]=='$' ||p[i]=='%' ||p[i]=='^' ||p[i]=='&' ||p[i]=='*' ||p[i]=='(' ||p[i]==')' ||p[i]=='-' ||p[i]=='+')spl=1;
            else if(p[i]=='0' ||p[i]=='1' ||p[i]=='2' ||p[i]=='3' ||p[i]=='4' ||p[i]=='5' ||p[i]=='6' ||p[i]=='7' ||p[i]=='8' ||p[i]=='9'  )digit=1;
        return lowercase&& upper&& spl&&digit;
    }
};