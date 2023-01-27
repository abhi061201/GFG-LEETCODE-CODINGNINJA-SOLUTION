class TrieNode{
    public:
    TrieNode* links[26];
    int eow;
    TrieNode()
    {
        for(int i=0 ; i<26; i++)
        {
            links[i]=NULL;
        }
        eow=0;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie()
    {
        root= new TrieNode();
    }
    void insert(string &s)
    {
        TrieNode* temp= root;
        for(auto it: s)
        {
            if(!temp->links[it-'a'])temp->links[it-'a']= new TrieNode();
            temp= temp->links[it-'a'];
        }
        temp->eow++;
    }
    
    bool check(string &s)
    {
        
        
        if(go(0, s, 0))return 1;
        return 0;
    }
    
    bool check_helper(int i, TrieNode* temp, string &s, int take)
    {
        if(i==s.length())
        {
            if(take>1)return 1;
            return 0;
        }
        if(!temp->links[s[i]-'a'])return 0;
        
        bool partition=0, n_part=0;
        if(temp->links[s[i]-'a']->eow>=1 )
        {
            TrieNode* newNode= root;
           partition= check_helper(i+1, newNode, s, 1+take);
        }
        
       
        n_part= check_helper(i+1,temp->links[s[i]-'a'],s,take);
            
        return partition|n_part;
        
    }
    bool go(int i, string &s, int count)
    {
        if(i==s.length())
        {
            return count>1;
            
        }
        TrieNode* temp= root;
        
        for(int start= i; start<s.length(); start++)
        {
            if(!temp->links[s[start]-'a'])return 0;
            temp= temp->links[s[start]-'a'];
            if(temp->eow >=1)
            {
                if(go(start+1, s, 1+count))return 1;
            }
            
            
        }
        return 0;
    }
    
};
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie t;
        // cout<<words.size();
        for(auto it:words)
        {
            t.insert(it);
        }
        vector<string>ans;
        
        for(auto it: words)
        {
            if(t.check(it))ans.push_back(it);
        }
        return ans;
    }
};