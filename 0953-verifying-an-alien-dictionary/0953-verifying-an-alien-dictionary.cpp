class Solution {
public:
    map<char, int>mp;
    bool isAlienSorted(vector<string>& words, string order) {
        
        int n= order.length();
        for(int i=0; i<n; i++)
        {
            mp[order[i]]=i;
        }
        int m= words.size();
        for(int i=0; i<m-1; i++)
        {
            if(!check(words[i], words[i+1]))return 0;
        }
        return 1;
    }
    bool check(string &first, string &second)
    {
        // cout<<first<<" : "<<second<<endl; 
        int i=0;
        int n= first.length();
        int m= second.length();
        while(i<min(first.length(),second.length()))
        {
            if(mp[first[i]] < mp[second[i]])return 1;
            else if(mp[first[i]] > mp[second[i]])return 0;
            // cout<<i<<endl;
            i++;      
        }
        if(n!=m)
        {
            if(m<n && i==m)return 0;
            
        }
        return 1;
    }
};