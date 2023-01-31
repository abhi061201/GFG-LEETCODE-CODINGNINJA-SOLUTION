class TrieNode
{
    public:
    TrieNode* links[26];
    int eow;
    TrieNode()
    {
        eow=0;
        for(int i=0; i<26;i++)links[i]=NULL;
    }
};
class Trie
{
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
    bool checkmatch(string &s)
    {
        TrieNode*temp = root;
        
        return go(temp, s, 2, 0);
    }
    bool go(TrieNode* temp, string & s, int steps, int ind)
    {
        if(steps<0 || ind==s.length())return steps>=0;
        bool ans=0;
        for(int i=0; i<26; i++)
        {
            if(temp->links[i])
            {
                ans= ans|go(temp->links[i], s, steps- (i+'a'!=s[ind]), ind+1 );
            }
        }
        return ans;
    }
    
};
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        Trie t;
        for(auto it: dictionary)
        {
            t.insert(it);
        }
        vector<string >ans;
        for(auto it: queries)
        {
            if(t.checkmatch(it))ans.push_back(it);
        }
        return ans;
    }
};