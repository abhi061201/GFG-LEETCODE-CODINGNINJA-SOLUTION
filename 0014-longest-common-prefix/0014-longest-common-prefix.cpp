class TrieNode
{
    public:
    TrieNode* link[26];
    int leaf;
    TrieNode()
    {
        for(int i=0; i<26; i++)link[i]= NULL;
        leaf=0;
    }
};
class Trie
{
    TrieNode* root;
    
    public: 
    Trie()
    {
        root= new TrieNode();
    }
    void insert(string &s)
    {
        TrieNode* temp= root;
        for(auto it: s)
        {
            if(!temp->link[it-'a'])temp->link[it-'a']= new TrieNode();
            temp= temp->link[it-'a'];
            temp->leaf++;
        }
        
    }
    string LongPrefix(string &s, int n)
    {
        string longest_prefix="";
        TrieNode* temp= root;
        for(auto it: s)
        {
            if(!temp->link[it-'a'])break;            
            temp = temp->link[it-'a'];
            if(temp->leaf!=n)break;
            longest_prefix.push_back(it);
        }
        return longest_prefix;
        
        
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        Trie t;
        for(auto it: strs)t.insert(it);
        return t.LongPrefix(strs[0], n);
    }
};