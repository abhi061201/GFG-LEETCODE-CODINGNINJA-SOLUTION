class Solution {
public:
    int maxVowels(string s, int k) {
        int n= s.length(),  ans=0, temp=0;
        for(int j=0,i=0 ; j<n;j++)
        {
            
            if(j-i+1<=k)
            {
                if(vowel(s[j]))temp++;
            }
            else {
                
                if(vowel(s[i++]))temp--;
                if(vowel(s[j]))temp++;
            }
            ans= max(ans, temp);
        }
        return ans;
    }
    bool vowel(char &c)
    {
        if(c=='a'|| c=='e'|| c== 'i'|| c=='o'|| c=='u')return 1;
        return 0;
    }
};