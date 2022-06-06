class Solution {
public:
    int minimumMoves(string s) {
        string k=s;
        int n= s.length();
        int count1=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='X'){
               for(int j=0 ; j<3 ; j++){
                   if(i+j==n)break;
                   s[i+j]='O';
               }
                count1++;
            }
        }
        s=k;
        reverse(s.begin(),s.end());
        int count2=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='X'){
               for(int j=0 ; j<3 ; j++){
                   if(i+j==n)break;
                   s[i+j]='O';
               }
                count2++;
            }
        }
        return min(count1,count2);
        
    }
};
