class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n= s.length();
        int ans= n;
        int countmin=0, countone=0;
        for(char c: s)
        {
            if(c=='1')
            {
                countone++;
            }
            else
            {
                countmin++;
                countmin= min(countmin, countone);
            }
            
        }
        return countmin;
    }
};