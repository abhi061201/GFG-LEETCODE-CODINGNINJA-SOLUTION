class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> ct(7),cb(7),same(7);
        int n=tops.size();
        for(int i=0;i<n;i++){
            ct[tops[i]]++;
            cb[bottoms[i]]++;
            if(tops[i]==bottoms[i])
                same[tops[i]]++;
        }
        for(int i=1;i<7;i++){
            if(ct[i]+cb[i]-same[i]==n)
                return n-max(ct[i],cb[i]);
        }
        
        return -1;
    }
};
