class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int x= c1[0] -'a';
        int y= c1[1] -'1';
        
        int x2= c2[0] -'a';
        int y2= c2[1] -'1';
        
        
        if(((x2-x) +(y2-y))%2==0)return 1;
        return 0;
    }
};