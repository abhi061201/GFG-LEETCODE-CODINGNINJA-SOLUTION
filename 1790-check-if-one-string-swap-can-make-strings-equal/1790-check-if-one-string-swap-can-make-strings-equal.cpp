class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff =0, n= s1.length();
        for(int i=0; i<n;i++){
            if(s1[i]!= s2[i]){
                diff++;
            }
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if(s1==s2 && (diff==0 ||diff==2))return 1;
        return 0;
    }
};