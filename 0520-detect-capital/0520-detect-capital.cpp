class Solution {
public:
    bool detectCapitalUse(string word) {
        int n= word.length();
        //check all capital
        bool allcap=true, allsmall=true, firstcap=true, othersmall=true;;
        for(int i=0; i<n;i++)
        {
            if(word[i] >='a' && word[i]<='z')allcap=0;
            if(i!=0 && word[i] >='A' && word[i]<='Z')
            {
                allsmall=0;
                othersmall=0;
                
            }
            if(i==0 && word[i] >='a' && word[i]<='z')
            {
                firstcap=0; 
            }
            
        }
        return (allcap || allsmall|| (firstcap && othersmall));
    }
};