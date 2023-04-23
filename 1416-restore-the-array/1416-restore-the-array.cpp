class Solution {
public:
    int convert(string& s)
    {    
        long num=0;
        for(char c:s)
        {
            int a=c-'0';
            num=num*10+a;
        }
        return num>INT_MAX?-1:num;
    }
    int helper(string& s, int& k, int index, vector<int>& dp)
    {
        if(index==s.length())
            return 1;
        if(dp[index]!=-1)
            return dp[index];
        int count=0;
        int size=s.length()-index<10?s.length()-index:10;
        for(int i=1;i<=size;i++)
        {
            string substring=s.substr(index,i);
            if(substring[0]=='0')
                continue;
            int num=convert(substring);
            if(num>=1 && num<=k)
            {
                count=(count+helper(s,k,index+i,dp))%1000000007;
            }
        }
        return dp[index]=count;
    }
    int numberOfArrays(string& s, int& k) {
        vector<int> dp(s.length(),-1);
        helper(s,k,0,dp);
        return dp[0];
    }
};