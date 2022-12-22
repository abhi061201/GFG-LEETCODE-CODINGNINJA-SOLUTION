class Solution {
public:
    int similarPairs(vector<string>& words) {
        int n= words.size();
        int count=0;
        for(int i=0; i<n; i++)
        {
            
            for(int j= 0;j!=i && j<n; j++)
            {
                if(check(words[i], words[j]) && check(words[j], words[i]) )count++;
            }
        }
        return count;
    }
    bool check(string &s1 , string &s2){
        set<char>st(s1.begin(), s1.end());
        for(auto it: s2){
            if(st.find(it)==st.end())return 0;
            
        }
        return 1;
        
    }
};